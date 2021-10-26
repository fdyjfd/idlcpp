// idlcpp.cpp : Defines the entry point for the console application.
//

#include "idlcpp.h"
#include "yyfuncs.h"
#include "Platform.h"
#include "SourceFile.h"
#include "ErrorList.h"
#include "ImportDirectory.h"
#include "Options.h"
#include <string>
#include <assert.h>
#include "Compiler.h"
#include <filesystem>
#include <iostream>
using namespace std;
using namespace std::filesystem;

#ifdef __cplusplus
extern "C"
{
#endif
#include "idlcpp.y.h"

#ifdef __cplusplus
}
#endif

extern "C"
{
  int yyparse();
  void yyrestart(FILE* input_file);
}

void ShowDefaultInfo()
{
  printf("idlcpp Compiler Version 1.0\n"
    "Copyright (C) Peng Aifeng 2011-2016. All rights reserved.\n");
  printf("No files specified, use -h to get usage information\n");
}

void ShowHelpInfo()
{
  printf("idlcpp Compiler Version 1.0\n"
    "Copyright (C) Peng Aifeng 2011-2016. All rights reserved.\n");
  printf(
    "usage: idlcpp [options] [file]\n\n"
    "-h\t\t\t print this message\n"
    "-ld\t\t\t add line directive in header file\n"
    "-pc<dir>\t\t set path of pafcore header files\n"
    "-mp<postfix>\t\t define meta wrapper type postfix\n"
    "-sp<postfix>\t\t define subclass proxy type postfix\n"
    "-ic<postfix>\t\t define internal source file postfix\n"
    "-mh<postfix>\t\t define meta header file postfix\n"
    "-mc<postfix>\t\t define meta source file postfix\n"
    "-em<macro>\t\t set vc dllexport macro\n"
    "-I<dir>\t\t\t add to import search path\n"
    "-sac\t\t\t strict arguments count\n"
    "-cc\t\t\t check constant\n"
  );
}

extern "C"
{
  extern int yylineno;
  extern int yytokenno;
  extern int yyHasArrayProperty;
  extern int yyHasListProperty;
  extern int yyHasMapProperty;
  extern int yyHasDelegate;
  typedef struct yy_buffer_state* YY_BUFFER_STATE;
  YY_BUFFER_STATE createBufferState(FILE* file);
  YY_BUFFER_STATE yy_scan_string(const char* yy_str);
  YY_BUFFER_STATE yy_scan_buffer(char* base, unsigned int size);
  void yy_switch_to_buffer(YY_BUFFER_STATE new_buffer);
  void yy_delete_buffer(YY_BUFFER_STATE b);
}

void ParseOption(const char* arg)
{
  if (strncmp(arg + 1, "h", 1) == 0)
  {
    ShowHelpInfo();
  }
  else if (strncmp(arg + 1, "ld", 2) == 0)
  {
    g_options.m_outputLineDirective = true;
  }
  else if (strncmp(arg + 1, "pc", 2) == 0)
  {
    g_options.setPafcorePath(arg + 3);
    g_importDirectories.addImportDirectory(arg + 3);
  }
  else if (strncmp(arg + 1, "mp", 2) == 0)
  {
    g_options.m_metaTypePostfix = arg + 3;
  }
  else if (strncmp(arg + 1, "sp", 2) == 0)
  {
    g_options.m_subclassProxyPostfix = arg + 3;
  }
  else if (strncmp(arg + 1, "ic", 2) == 0)
  {
    g_options.m_internalSourceFilePostfix = arg + 3;
  }
  else if (strncmp(arg + 1, "mh", 2) == 0)
  {
    g_options.m_metaHeaderFilePostfix = arg + 3;
  }
  else if (strncmp(arg + 1, "mc", 2) == 0)
  {
    g_options.m_metaSourceFilePostfix = arg + 3;
  }
  else if (strncmp(arg + 1, "em", 2) == 0)
  {
    g_options.m_exportMacro = arg + 3;
  }
  else if (strncmp(arg + 1, "I", 1) == 0)
  {
    g_importDirectories.addImportDirectory(arg + 2);
  }
  else if (strncmp(arg + 1, "sac", 3) == 0)
  {
    g_options.m_strictArgumentsCount = true;
  }
  else if (strncmp(arg + 1, "cc", 2) == 0)
  {
    g_options.m_checkConstant = true;
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    ShowDefaultInfo();
    return 0;
  }

  for (int i = 1; i < argc; ++i)
  {
    if ('-' == *argv[i])
    {
      ParseOption(argv[i]);
    }
  }

  //获取要处理的文件
  const char* fileName = argv[argc - 1];
  path file(fileName);
  if (!fileExisting(file)) {
    cout << u8"Please input .i file absolute path." << endl;
    return 0;
  }

  g_importDirectories.setCurrentDirectory(file);
  g_importDirectories.convertToAbsoluteDirectory();
  g_options.convertToAbsoluteDirectory();
  path fileWithoutExt = file;
  fileWithoutExt.replace_extension();

  std::string outputFileName = fileWithoutExt.u8string();

  bool mainSourceFile = true;

  if (import_file_failed == g_compiler.addSourceFile(file))
  {
    ErrorList_AddItem("", 0, 0, import_error_file_not_existing, fileName);
  }
  while (SourceFile* sourceFile = g_compiler.popSourceFile())
  {
    path currFile = sourceFile->m_file;
    g_importDirectories.setCurrentDirectory(currFile);

    FILE* file = fopen(sourceFile->m_file.u8string().c_str(), "r");
    if (0 == file)
    {
      break;
    }
    g_compiler.prepareParse(sourceFile, mainSourceFile);
    yyrestart(file);
    yylineno = 1;
    yytokenno = 0;
    yyHasArrayProperty = 0;
    yyHasListProperty = 0;
    yyHasMapProperty = 0;
    yyHasDelegate = 0;
    yyparse();
    fclose(file);
    sourceFile->m_hasArrayProperty = (0 != yyHasArrayProperty);
    sourceFile->m_hasListProperty = (0 != yyHasListProperty);
    sourceFile->m_hasMapProperty = (0 != yyHasMapProperty);
    sourceFile->m_hasDelegate = (0 != yyHasDelegate);

    mainSourceFile = false;
  }
  if (0 != ErrorList_ErrorCount())
  {
    ErrorList_Output();
    return -1;
  }
  g_compiler.extendInternalCode();
  g_compiler.collectTypes();
  if (0 != ErrorList_ErrorCount())
  {
    ErrorList_Output();
    return -2;
  }
  g_compiler.checkTypeNames();
  if (0 != ErrorList_ErrorCount())
  {
    ErrorList_Output();
    return -3;
  }
  g_compiler.checkSemantic();
  if (0 != ErrorList_ErrorCount())
  {
    ErrorList_Output();
    return -4;
  }
  assert(0 == ErrorList_ErrorCount());
  g_compiler.generateCode(outputFileName.c_str());
  return 0;
}

