/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 05:28:33 -0700
 * @LastEditTime: 2019-09-04 02:10:02 -0700
 * @LastEditors: 
 * @Description: 
 */


#include "head.h"
#include "callbacks.h"
#include "interface.h"

int main (int argc , gchar* argv[])
{
    GtkWidget * TalkWindow ;
    gtk_init(&argc,&argv);
    TalkWindow = CreateTalkWindow();

    g_signal_connect(G_OBJECT(TalkWindow),"delete_event",
    G_CALLBACK(on_window_delete_event),NULL);
    gtk_widget_show(TalkWindow);
    gtk_main();
    return FALSE;
}








