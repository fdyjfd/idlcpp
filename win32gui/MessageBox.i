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
		static void Show(void ptr hwnd, const char ptr text, const char ptr caption, uint_t flag);
	};
}
