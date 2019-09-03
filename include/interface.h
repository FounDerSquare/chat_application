/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 09:02:24 -0700
 * @LastEditTime: 2019-09-02 00:31:34 -0700
 * @LastEditors: 
 * @Description: 
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__


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

typedef struct sticker_info{
    GtkWidget *sticker_window;
    GtkTextBuffer *view_buffer; //文本缓冲区
    char *str;   //表情的名字
    struct sticker_info **spointer;
}Emoji;

typedef struct text_view_info{
    GtkWidget *view;
    GtkTextBuffer *view_buffer;
}TextView;

typedef struct from_to_windows{
    GtkTextBuffer *from;
    GtkTextBuffer *to;
}FromToWin;

///////////////函数声明区//////////////
void on_send(GtkButton * button,FromToWin* ftw);
GtkWidget* CreateTalkWindow( void );

#endif
