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
#include <tchar.h>


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
	int yyparse ();
	void yyrestart( FILE *input_file);
}

void ShowDefaultInfo()
{
	printf("idlcpp Compiler Version 1.0\n"
		"Copyright (C) 2007-2013 Aifeng Peng. All rights reserved.\n");
	printf("No files specified, use -h to get usage information\n");
}

void ShowHelpInfo()
{
	printf("idlcpp Compiler Version 1.0\n"
		"Copyright (C) 2007-2013 Aifeng Peng. All rights reserved.\n");
	printf(
		"usage idlcpp [options] [file]\n\n"
		"-h\t\t\t print this message\n"
		"-ld\t\t\t add line directive in header file\n"
		"-pc<path>\t\t set path of pafcore header files\n"
		"-mp<postfix>\t\t define meta wrapper type postfix\n"
		"-ip<postfix>\t\t define interface wrapper type postfix\n"
		"-ic<postfix>\t\t define partial source file postfix\n"
		"-mh<postfix>\t\t define meta header file postfix\n"
		"-mc<postfix>\t\t define meta source file postfix\n"
		"-em<macro>\t\t set vc dllexport macro\n"
		);
}

extern "C"
{
extern int yylineno;
extern int yytokenno;
typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE createBufferState(FILE* file);
YY_BUFFER_STATE yy_scan_string( const char *yy_str );
YY_BUFFER_STATE yy_scan_buffer( char *base, unsigned int size );
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
void yy_delete_buffer( YY_BUFFER_STATE b );
}

void ParseOption(const char* arg)
{
	if(strncmp(arg + 1, "h", 1) == 0)
	{
		ShowHelpInfo();
	}
	else if(strncmp(arg + 1, "ld", 2) == 0)
	{
		g_options.m_outputLineDirective = true;
	}	
	else if(strncmp(arg + 1, "pc", 2) == 0)
	{
		g_options.setPafcorePath(arg + 3);
	}
	else if(strncmp(arg + 1, "mp", 2) == 0)
	{
		g_options.m_metaTypePostfix = arg + 3;
	}
	else if(strncmp(arg + 1, "ip", 2) == 0)
	{
		g_options.m_interfaceImplementorPostfix = arg + 3;
	}
	else if(strncmp(arg + 1, "ic", 2) == 0)
	{
		g_options.m_partialSourceFilePostfix = arg + 3;
	}
	else if(strncmp(arg + 1, "mh", 2) == 0)
	{
		g_options.m_metaHeaderFilePostfix = arg + 3;
	}
	else if(strncmp(arg + 1, "mc", 2) == 0)
	{
		g_options.m_metaSourceFilePostfix = arg + 3;
	}
	else if(strncmp(arg + 1, "em", 2) == 0)
	{
		g_options.m_exportMacro = arg + 3;
	}
}

void ParseConfigFile();
int _tmain(int argc, _TCHAR* argv[])
{
	if(argc < 2)
	{
		ShowDefaultInfo();
		return 0;
	}

	ParseConfigFile();
	for(int i = 1; i < argc; ++i)
	{
		if('-' == *argv[i])
		{
			ParseOption(argv[i]);
		}
	}	

	std::string inputFileName;
	normalizeFileName(inputFileName, argv[argc - 1]);

	const char* extName = getExtNameBegin(inputFileName.c_str());
	std::string outputFileName;
	if(0 == extName)
	{
		outputFileName.assign(inputFileName);
	}
	else
	{
		outputFileName.assign(inputFileName.c_str(), extName);
	}

	bool mainSourceFile = true;
	g_sourceFileManager.addSourceFile(inputFileName.c_str());
	while(SourceFile* sourceFile = g_sourceFileManager.popSourceFile())
	{
		const char* dirEnd = getDirNameEnd(sourceFile->m_fileName.c_str());
		if(dirEnd)
		{
			std::string dirName(sourceFile->m_fileName.c_str(), dirEnd);
			g_importDirectories.setCurrentDirectory(dirName.c_str());
			FILE* file = fopen(sourceFile->m_fileName.c_str(), "r");
			if(0 == file)
			{
				break;
			}
			g_sourceFileManager.prepareParse(sourceFile, mainSourceFile);
			yyrestart(file);
			yylineno = 1;
			yytokenno = 0;
			yyparse();
			fclose(file);
			//fseek(file, 0, SEEK_END);
			//long size = ftell(file);
			//fseek(file, 0, SEEK_SET);
			//char* buf = new char[size + 2];
			//memset(buf, 0, size + 2);
			//fread(buf, 1, size, file);
			//fclose(file);
			//size_t len = strlen(buf);
			//YY_BUFFER_STATE bs = yy_scan_buffer(buf, len + 2);
			//yy_switch_to_buffer(bs);
			//yyparse();
			//yy_delete_buffer(bs);
			//delete []buf;
		}
		mainSourceFile = false;
	}
	if(0 != ErrorList_ErrorCount())
	{
		ErrorList_Output();
		return -1;
	}
	g_sourceFileManager.checkTypeInfos();
	if(0 != ErrorList_ErrorCount())
	{
		ErrorList_Output();
		return -2;
	}
	g_sourceFileManager.checkSemantic();
	if(0 != ErrorList_ErrorCount())
	{
		ErrorList_Output();
		return -3;
	}
	g_sourceFileManager.generateCode(outputFileName.c_str());
	return 0;
}

