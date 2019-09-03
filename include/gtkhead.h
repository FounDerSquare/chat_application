/*
 * @Copyright: CS of BIT
 * @Author: 邓方晴
 * @File name: Gtk_CustomStruct.h
 * @Version: 1.0
 * @Date: 2019-08-30 00:36:39 -0700
 * @LastEditTime: 2019-09-02 00:30:57 -0700
 * @LastEditors: 
 * @Description: 编程过程中可能用到一些自定义的数据结构
 *               统一在这里进行定义。
 */
#ifndef GTKHEAD_H
#define GTKHEAD_H

///////////////结构体定义区////////////
/**
 * @Author: 邓方晴
 * @Description: WINAPPEAR 数据类型
 *               包含窗口标题、宽高、位置信息
 */
typedef struct _WinAppear
{
    gchar* title;
    gint width,height;
    GtkWindowPosition position;
}WINAPPEAR;


///////////////函数声明区//////////////

//GString getLocalTime();


#endif

