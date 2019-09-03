/*
 * @Copyright: CS of BIT
 * @Author: 邓方晴
 * @File name: 
 * @Version: 
 * @Date: 2019-08-30 00:09:11 -0700
 * @LastEditTime: 2019-09-02 00:37:33 -0700
 * @LastEditors: 
 * @Description: 
 */

#include "head.h"
#include "interface.h"

//char nowtime[30];

//FromToWin* chat;

enum {
    PIXBUF_COL,
    TEXT_COL
};

// void getThisTime()
// {
//     time_t now ;
//     struct tm *l_time;
//     now = time((time_t *)NULL);
//     l_time = localtime(&now); //取本地时间
//     memset(nowtime,0,sizeof(nowtime));
//     sprintf(nowtime,"%d/%d/%d  %d:%d:%d",l_time->tm_year+1900,l_time->tm_mon+1,l_time->tm_mday,l_time->tm_hour,l_time->tm_min,l_time->tm_sec);
// }


// GtkTreeModel* createModel() {
//     // const gchar *files[] = {"/home/new/chat/image/1200.jpg", "/home/new/chat/image/640.jpg",
//     //                         "/home/new/chat/image/201.jpg", "/home/new/chat/image/202.jpg"};
//     const gchar *files[] = {"1200.jpg", "640.jpg",
//                             "01.jpg", "202.jpg"};
//     GdkPixbuf *pixbuf;
//     GtkTreeIter iter;
//     GtkListStore *store;
//     gint i;

//     store = gtk_list_store_new(2, GDK_TYPE_PIXBUF, G_TYPE_STRING);

//     for(i = 0; i < 4; i++) {
//         pixbuf = gdk_pixbuf_new_from_file(files[i], NULL);
//         gtk_list_store_append(store, &iter);
//         gtk_list_store_set(store, &iter,
//                            PIXBUF_COL, pixbuf,
//                            TEXT_COL, files[i],
// 		           -1);       
//         gdk_pixbuf_unref(pixbuf);
//     }

//     return GTK_TREE_MODEL(store);
// }

// GtkWidget* createTreeView() {
//     GtkWidget *treeView;
//     GtkTreeViewColumn *column;
//     GtkCellRenderer *renderer;

//     treeView = gtk_tree_view_new_with_model(createModel());

//     renderer = gtk_cell_renderer_pixbuf_new();
//     column = gtk_tree_view_column_new_with_attributes(
//                      "Icon", renderer,
//                      "pixbuf", PIXBUF_COL,
//                       NULL);
//     gtk_tree_view_append_column(GTK_TREE_VIEW (treeView), column);

//     renderer = gtk_cell_renderer_text_new();
//     column = gtk_tree_view_column_new_with_attributes(
//                      "Filename", renderer,
//                      "text", TEXT_COL,
//                       NULL);
//     gtk_tree_view_append_column(GTK_TREE_VIEW (treeView), column);

//     return treeView;
// }

// void on_send(GtkButton * button,FromToWin* ftw)
// {
//     gchar *message;
//     GtkTextIter start,end;
//     GtkTextBuffer *showbuffer,*editbuffer;
//     //chat = data;
//     editbuffer = ftw->from;
//     showbuffer = ftw->to;
//     // GString* nowtime;
//     // char* tmp = getLocalTime();
//     // printf("tmpc is %s\n",tmp);
//     // printf("%s\n",getLocalTime());
//     // g_string_printf(nowtime,getLocalTime());
//     // printf("nowtime is: %s\n",nowtime);
//     //memset(nowtime,'\0',sizeof(nowtime));
//     if(isconnected==FALSE)  return;
//     //message = gtk_entry_get_text(GTK_ENTRY(message_entry));
//     gtk_text_buffer_get_bounds(editbuffer,&start,&end);
//     //const GtkTextIter s=start,e=end;
//     message = gtk_text_buffer_get_text(editbuffer,&start,&end,FALSE);
//     //memset(&sendbuf,0,sizeof(sendbuf));
//     //printf("%s/n",sendbuf);
//     //write(client_fd,sendbuf,1024);
//     //gtk_entry_set_text(GTK_ENTRY(message_entry),"");
//     gtk_text_buffer_set_text(editbuffer,"",1);
//     gtk_text_buffer_get_end_iter(showbuffer,&end);
//     gtk_text_buffer_insert(showbuffer,&end,"server:  ",-1);
//     gtk_text_buffer_get_end_iter(showbuffer,&end);
//     //nowtime = getLocalTime();
//     //strcpy(nowtime,getLocalTime());
//     //printf("nowtime is: %s\n",nowtime);
//     // gtk_text_buffer_insert(showbuffer,&end,nowtime,-1);
//     // gtk_text_buffer_get_end_iter(showbuffer,&end);
//     gtk_text_buffer_insert(showbuffer,&end,"\n",-1);
//     gtk_text_buffer_get_end_iter(showbuffer,&end);
//     gtk_text_buffer_insert(showbuffer,&end,message,-1);
//     gtk_text_buffer_get_end_iter(showbuffer,&end);
//     gtk_text_buffer_insert(showbuffer,&end,"\n",-1);
// }

// int main(int argc, char *argv[]) {
//     GtkWidget *window,*scwin;
//     GtkWidget *hPaned,*vPaned,*view1,*view2,*hbox;
//     GtkWidget *treeView;
//     GtkWidget *button;
//     GtkTextBuffer *buffer,*buffer2;

//     gtk_init(&argc, &argv);

//     window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//     gtk_window_set_title(GTK_WINDOW(window), "消息发送窗口");
//     gtk_window_set_default_size(GTK_WINDOW(window), 800, 500);
//     gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
//     gtk_container_set_border_width(GTK_CONTAINER(window),10);

//     hPaned = gtk_hpaned_new();
//     vPaned = gtk_vpaned_new();
//     gtk_paned_set_position(hPaned,100);
//     gtk_paned_set_position(vPaned,350);

//     hbox = gtk_hbox_new(FALSE,3);

//     treeView = createTreeView();

//     gtk_paned_add1(GTK_PANED(hPaned), treeView);
//     gtk_paned_add2(GTK_PANED(hPaned), vPaned);

//     scwin = gtk_scrolled_window_new(NULL,NULL);
//     gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scwin),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
//     view1 = gtk_text_view_new();
//     gtk_paned_add1(GTK_PANED(vPaned),scwin);
//     gtk_container_add(GTK_CONTAINER(scwin),view1);
//     buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view1));

//     // gtk_text_buffer_create_tag(buffer, "blue_foreground","foreground", "blue", NULL);//创建前景标记
//     // gtk_text_buffer_create_tag(buffer, "yellow_background", "background","yellow",NULL);//创建背景标记
//     // gtk_text_buffer_get_end_iter(buffer,&end);
//     // gtk_text_buffer_insert(buffer,&end,"这是一段正常的文字。",-1);
//     // //从此处开始带标记插入文字
//     // gtk_text_buffer_get_end_iter(buffer,&end);
//     // gtk_text_buffer_insert_with_tags_by_name(buffer,&end,"这是一段设了标记的文字。\n",-1,"blue_foreground",NULL);
//     // gtk_text_buffer_get_end_iter(buffer,&end);
//     // gtk_text_buffer_insert_with_tags_by_name(buffer,&end,"这是一段背景是黄色的文字。", -1, "yellow_background",NULL);

//     showbuffer=buffer;
    
//     scwin = gtk_scrolled_window_new(NULL,NULL);
//     gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scwin),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
//     view2 = gtk_text_view_new();//创建第二个文本视图控件
//     buffer2 = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view2));

//     button=gtk_button_new_with_label("发送");
//     //gtk_paned_pack2(GTK_PANED(vPaned),button,FALSE,FALSE);
//     //gtk_container_add(GTK_CONTAINER(view2),button);
//     g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_send),view2);

//     gtk_paned_add2(GTK_PANED(vPaned),hbox);
//     gtk_box_pack_end(hbox,button,FALSE,FALSE,0);
//     gtk_box_pack_end(hbox,scwin,TRUE,TRUE,0);
//     gtk_container_add(GTK_CONTAINER(scwin),view2);

//     gtk_container_add(GTK_CONTAINER(window), hPaned);

//     g_signal_connect(GTK_OBJECT(window), "destroy",
//                      G_CALLBACK(gtk_main_quit), NULL);

//     gtk_widget_show_all(window);

//     gtk_main();

//     return 0;
// }