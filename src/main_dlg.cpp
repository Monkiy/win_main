#include "main_dlg.h"
#include "win_dlg.h"

main_dlg & main_dlg::get_instance()
{
    static main_dlg dlg;
    return dlg;
}

main_dlg::main_dlg():
    __hwnd(0)
{
    strncpy(__title, "main_dlg", sizeof(__title));
    strncpy(__windows_class, "main_dlg", sizeof(__windows_class));
    win_dlg::register_class(main_dlg::win_msg_proc, __windows_class);
}

void main_dlg::exec()
{
    // 执行应用程序初始化: 
    if (!init_instance(SW_SHOW))
        return;

    //HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32TEST));

    MSG msg;

    // 主消息循环: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT main_dlg::win_msg_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 在此处添加使用 hdc 的任何绘图代码...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

BOOL main_dlg::init_instance(int nCmdShow)
{
    HINSTANCE hInstance = ::GetModuleHandle(NULL);//实例句柄

    __hwnd = CreateWindow(__windows_class, __title, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!__hwnd)
    {
        return FALSE;
    }

    ShowWindow(__hwnd, SW_SHOW);
    UpdateWindow(__hwnd);

    return TRUE;
}
