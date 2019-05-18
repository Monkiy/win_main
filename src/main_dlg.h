#pragma once
#include <Windows.h>

#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

class main_dlg
{
public:
    static main_dlg& get_instance();
    void exec();
private:
    main_dlg();
    main_dlg(const main_dlg&);
    static LRESULT CALLBACK win_msg_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    BOOL init_instance(int nCmdShow);

private:
    TCHAR __title[128];
    TCHAR __windows_class[128];
    HWND __hwnd;
};