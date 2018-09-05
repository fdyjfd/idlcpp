#import "typedef.i"

namespace win32gui
{
	enum MessageBoxButton
	{
		OK,
		OKCancel,
		AbortRetryIgnore,
		YesNoCancel,
		YesNo,
		RetryCancel,
	};
	struct MessageBox
	{
		static void Show(void * hwnd, const char * text, const char * caption, uint32_t flag);
	};
}
