#pragma once
#include <Windows.h>

namespace win_dlg
{
    //窗口回调函数定义
    typedef LRESULT(*win_dlg_call_back)(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    //注册窗口类
    ATOM register_class(win_dlg_call_back call_back_ptr, TCHAR* window_class_name);
}