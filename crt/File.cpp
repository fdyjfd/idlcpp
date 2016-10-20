#include "File.h"
#include "File.mh"
#include "File.ic"
#include "File.mc"
#include <stdio.h>

namespace crt
{

	File* File::New(const char * path, const char * mode)
	{
		FILE* file = fopen(path, mode);
		return (File*)file;
	}

	void File::Delete(File* file)
	{
		fclose((FILE*)file);
	}

	File* File::Open(const char * path, const char * mode)
	{
		FILE* file = fopen(path, mode);
		return (File*)file;
	}

	void File::Close(File* file)
	{
		fclose((FILE*)file);
	}
	
	//void File::__destroyInstance__(File* file)
	//{
	//	fclose((FILE*)file);
	//}

	size_t File::read(void * buffer, size_t size)
	{
		return fread(buffer, size, 1, (FILE*)this);
	}

	int File::seek(long offset, SeekFlag flag)
	{
		return fseek((FILE*)this, offset, flag);
	}

	long File::tell()
	{
		return ftell((FILE*)this);
	}

}