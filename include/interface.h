/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 09:02:24 -0700
 * @LastEditTime: 2019-09-03 08:30:26 -0700
 * @LastEditors: 
 * @Description: 
 */
#ifndef __INTERFACE_H__
#define __INTERFACE_H__


///////////////结构体定义区////////////

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

/**
 * @Author: 邓方晴
 * @Description: 聊天窗口属性信息传递用
 * @Param: FromToWin复合指针，用户自身ID，好友ID，好友资料卡面板TextView，用户资料卡面板TextView
 * @Throw: 
 */
typedef struct _chat_window{
    gchar* UserID;
    gchar* FriendID;
    FromToWin ftw;
    TextView* friendcard;
    TextView* mycard;
}ChatWindow;

///////////////函数声明区//////////////
void on_send(GtkButton * button,FromToWin* ftw);
GtkWidget* CreateTalkWindow( void );

#endif
