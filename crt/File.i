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
		static File new New(const char ptr path, const char ptr mode);
		static void Delete(File ptr file);
		static File ptr Open(const char ptr path, const char ptr mode);
		static void Close(File ptr file);

		size_t read(void ptr buffer, size_t size);
		int seek(long offset, SeekFlag flag);
		long tell();
	};
}
