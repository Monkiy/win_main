#include "win_dlg.h"

ATOM win_dlg::register_class(win_dlg_call_back call_back_ptr, TCHAR* window_class_name)
{
    HINSTANCE hInstance = ::GetModuleHandle(NULL);

    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = call_back_ptr;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, NULL);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = window_class_name;
    wcex.hIconSm = LoadIcon(wcex.hInstance, NULL);
    return RegisterClassEx(&wcex);
}