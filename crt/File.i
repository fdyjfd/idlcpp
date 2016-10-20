#import "typedef.i"

namespace crt
{
	struct File
	{
		enum SeekFlag
		{
			seek_set,
			seek_cur,
			seek_end,
		};
		static File^ New(const char* path, const char* mode);
		static void Delete(File* file);
		static File* Open(const char* path, const char* mode);
		static void Close(File* file);
		static void __destroyInstance__(File* file) = "Close";
		size_t read(void* buffer, size_t size);
		int seek(long offset, SeekFlag flag);
		long tell();
	};
}
