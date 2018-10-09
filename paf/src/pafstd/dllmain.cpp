#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (DLL_PROCESS_ATTACH == dwReason)
	{
		OutputDebugStringA("pafstd Process Attach\n");
	}
	else if (DLL_PROCESS_DETACH == dwReason)
	{
		OutputDebugStringA("pafstd Process Detach\n");
	}
	return TRUE;
}
