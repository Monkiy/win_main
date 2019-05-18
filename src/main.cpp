/*
引用网站:https://www.cnblogs.com/CJWBLOG/p/5638424.html
一直以来，采用C语言方式的Windows编程的时候，
程序的入口必须是WinMain()函数，
当开始学习MFC的时候，又觉的MFC的框架结构繁冗混乱，
萌生了自己写一个窗口类编写Windows程序，
同时想和C#一样避开WinMain的启动函数，
所以在网上搜寻并总结了这样一篇文章，作为笔记和大家一起学习。
*/
#include "main_dlg.h"

int main()
{
    main_dlg::get_instance().exec();
    return 0;
}