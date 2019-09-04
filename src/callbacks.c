/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 19:45:05 -0700
 * @LastEditTime: 2019-09-03 10:47:45 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "interface.h"

static char nowtime[30];//全局变量，显示当前时间

/**
 * @Author: 邓方晴
 * @Description: 获得当前系统时间，返回字符串
 * @Param: 
 * @Return: 
 * @Throw: 
 */
void getThisTime()
{
    time_t now ;
    struct tm *l_time;
    now = time((time_t *)NULL);
    l_time = localtime(&now); //取本地时间
    memset(nowtime,'\0',sizeof(nowtime));
    sprintf(nowtime,"%d/%d/%d  %d:%d:%d",l_time->tm_year+1900,l_time->tm_mon+1,l_time->tm_mday,l_time->tm_hour,l_time->tm_min,l_time->tm_sec);
}

/**
 * @Author: 邓方晴
 * @Description: 满足不提前获知目标容量也可以合并字符串
 * @Param: 
 * @Return: 
 * @Throw: 
 */
void string_add(char*s1,char*s2)
{
    int len;

    len = strlen(s1);
    printf("\n");
    len+=strlen(s2);
    len +=5;
    char* temp;
    temp = (char*)malloc(sizeof(char)*len);
    strcpy(temp,s1);
    strcat(temp,s2);
    free(s1);
    s1 = temp;
}

/**
 * @Author: 王可欣
 * @Description: 在输入框中插入表情
 * @Param: 
 * @Return: 
 */
 void insert_sticker(GtkWidget *widget,GdkEventButton *event, Emoji *sinfo)
 {
    
    char head[30]="./bin/sticker";
	char tail[10]=".gif";
    for(int i=0;i<3;i++)
    head[13+i]=sinfo->str[i];
    for(int i=0;i<4;i++)
    head[16+i]=tail[i];
	g_printf("%s\n",head);
   
    GtkTextIter end;
    //获取缓冲区的尾部
    gtk_text_buffer_get_end_iter(sinfo->view_buffer,&end);
    
    GdkPixbuf *pixbuf=gdk_pixbuf_new_from_file(head,NULL);
    gtk_text_buffer_insert_pixbuf(sinfo->view_buffer,&end,pixbuf);
    //向缓冲区插入数据
   // gtk_text_buffer_insert(sinfo->view_buffer,&end,sinfo->str,-1);
    
    GtkWidget *sticker_window = sinfo->sticker_window;
    Emoji **p = sinfo->spointer;
    int i;
    for (i=0;i<6;i++) free(p[i]);
    free(p);
    gtk_widget_destroy(sticker_window);
}

/**
 * @Author: 王可欣
 * @Description: 销毁表情窗口
 * @Param: 
 * @Return: 
 */
void destory_sticker_window(GtkWidget *widget,GdkEventCrossing *event,GtkWidget* data){
    gtk_widget_destroy(data);
}

/**
 * @Author: 王可欣
 * @Description:按下插入表情按钮 
 * @Param: 
 * @Return: 
 */
void PressStickerBtn(GtkWidget *widget, GdkEvent *event, TextView *viewinfo){

        GdkEventButton *event_button = (GdkEventButton *) event;
           
            GtkWidget *sticker_window;
            GtkWidget *eventbox;
            GtkWidget *sbox1, *sbox2, *sbox3, *sbox4, *sbox5, *sbox6;  //盛放6个表情的eventbox
            GtkWidget *table;
            GtkWidget *s1, *s2, *s3, *s4, *s5, *s6; //6个表情的image

            sticker_window = gtk_window_new(GTK_WINDOW_POPUP);  //弹出式不边框窗口
            gtk_window_set_default_size(GTK_WINDOW(sticker_window),100,100);
            gtk_widget_set_size_request(sticker_window,200,100);
            gtk_window_set_position(GTK_WINDOW(sticker_window), GTK_WIN_POS_MOUSE);  //出现在鼠标位置

            eventbox = gtk_event_box_new();
            g_signal_connect(G_OBJECT(eventbox),"leave_notify_event",G_CALLBACK(destory_sticker_window),sticker_window);
            gtk_container_add(GTK_CONTAINER(sticker_window),eventbox);
            table = gtk_table_new(2,3,FALSE);
            gtk_container_add(GTK_CONTAINER(eventbox),table);

            sbox1 = gtk_event_box_new();
            sbox2 = gtk_event_box_new();
            sbox3 = gtk_event_box_new();
            sbox4 = gtk_event_box_new();
            sbox5 = gtk_event_box_new();
            sbox6 = gtk_event_box_new();

            Emoji **spointer = (Emoji **)malloc(sizeof(Emoji *)*6);

            Emoji *sinfo1 = (Emoji *)malloc(sizeof(Emoji));
            sinfo1->str = "/am";
            sinfo1->view_buffer = viewinfo->view_buffer;
            sinfo1->sticker_window = sticker_window;
            sinfo1->spointer = spointer;

            Emoji *sinfo2 = (Emoji *)malloc(sizeof(Emoji));
            sinfo2->str = "/dk";
            sinfo2->view_buffer = viewinfo->view_buffer;
            sinfo2->sticker_window = sticker_window;
            sinfo2->spointer = spointer;

            Emoji *sinfo3 = (Emoji *)malloc(sizeof(Emoji));
            sinfo3->str = "/fd";
            sinfo3->view_buffer = viewinfo->view_buffer;
            sinfo3->sticker_window = sticker_window;
            sinfo3->spointer = spointer;

            Emoji *sinfo4 = (Emoji *)malloc(sizeof(Emoji));
            sinfo4->str = "/sk";
            sinfo4->view_buffer = viewinfo->view_buffer;
            sinfo4->sticker_window = sticker_window;
            sinfo4->spointer = spointer;

            Emoji *sinfo5 = (Emoji *)malloc(sizeof(Emoji));
            sinfo5->str = "/wx";
            sinfo5->view_buffer = viewinfo->view_buffer;
            sinfo5->sticker_window = sticker_window;
            sinfo5->spointer = spointer;

            Emoji *sinfo6 = (Emoji *)malloc(sizeof(Emoji));
            sinfo6->str = "/zj";
            sinfo6->view_buffer = viewinfo->view_buffer;
            sinfo6->sticker_window = sticker_window;
            sinfo6->spointer = spointer;

            spointer[0] = sinfo1;
            spointer[1] = sinfo2;
            spointer[2] = sinfo3;
            spointer[3] = sinfo4;
            spointer[4] = sinfo5;
            spointer[5] = sinfo6;

            g_signal_connect(G_OBJECT(sbox1),"button_press_event",G_CALLBACK(insert_sticker),(gpointer)sinfo1);
            g_signal_connect(G_OBJECT(sbox2),"button_press_event",G_CALLBACK(insert_sticker),(gpointer)sinfo2);
            g_signal_connect(G_OBJECT(sbox3),"button_press_event",G_CALLBACK(insert_sticker),(gpointer)sinfo3);
            g_signal_connect(G_OBJECT(sbox4),"button_press_event",G_CALLBACK(insert_sticker),(gpointer)sinfo4);
            g_signal_connect(G_OBJECT(sbox5),"button_press_event",G_CALLBACK(insert_sticker),(gpointer)sinfo5);
            g_signal_connect(G_OBJECT(sbox6),"button_press_event",G_CALLBACK(insert_sticker),(gpointer)sinfo6);

            s1 = gtk_image_new_from_file("./bin/sticker/am.gif");
            s2 = gtk_image_new_from_file("./bin/sticker/dk.gif");
            s3 = gtk_image_new_from_file("./bin/sticker/fd.gif");
            s4 = gtk_image_new_from_file("./bin/sticker/sk.gif");
            s5 = gtk_image_new_from_file("./bin/sticker/wx.gif");
            s6 = gtk_image_new_from_file("./bin/sticker/zj.gif");

            gtk_container_add(GTK_CONTAINER(sbox1),s1);
            gtk_container_add(GTK_CONTAINER(sbox2),s2);
            gtk_container_add(GTK_CONTAINER(sbox3),s3);
            gtk_container_add(GTK_CONTAINER(sbox4),s4);
            gtk_container_add(GTK_CONTAINER(sbox5),s5);
            gtk_container_add(GTK_CONTAINER(sbox6),s6);

            gtk_table_attach_defaults(GTK_TABLE(table),sbox1,0,1,0,1);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox2,1,2,0,1);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox3,2,3,0,1);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox4,0,1,1,2);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox5,1,2,1,2);
            gtk_table_attach_defaults(GTK_TABLE(table),sbox6,2,3,1,2);
            
            gtk_widget_show_all(sticker_window);
}

static GtkWidget* dialog = NULL;
/*
 * @Author: 王可欣
 * @Description: 文件选择框点击取消
 * @Param: 
 * @Return: 
 */
void on_cancel (GtkButton *button,gpointer data)
{
    gtk_widget_destroy(dialog);
}

/**
 * @Author: 王可欣
 * @Description: 文件选择框中点击确定
 * @Param: 
 * @Return: 
 */
void on_ok (GtkButton* button, gpointer data)
{
    //filename是文件路径
    const char* filename;
    GtkWidget* window;
    filename = gtk_file_selection_get_filename(GTK_FILE_SELECTION(data));
    //g_print("xnjxnjzx");
    g_printf("%s\n",filename);
    //window = create_view(filename);
    //gtk_widget_show(window);
}


gboolean on_window_delete_event (GtkWidget* widget,GdkEvent *event,gpointer data)
{
    gtk_main_quit();
    return FALSE;
}


/**
 * @Author: 王可欣
 * @Description: 点击发送文件按钮的回调函数
 * @Param: 
 * @Return: 
 */
void on_file_open_activate (GtkMenuItem* menuitem,gpointer data)
{
    //函数创建文件选择的窗口
    g_printf(" njzznjnk");
     dialog = gtk_file_selection_new("请选择一个图像文件");
    g_signal_connect(G_OBJECT(dialog),"destroy",
                G_CALLBACK(gtk_widget_destroy),dialog);
    g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(dialog)->ok_button),
                                        "clicked", G_CALLBACK(on_ok),dialog);
    g_signal_connect_swapped(G_OBJECT(
                    GTK_FILE_SELECTION(dialog)->ok_button),
                    "clicked",G_CALLBACK(on_cancel),NULL);
    g_signal_connect(G_OBJECT(
                    GTK_FILE_SELECTION(dialog)->cancel_button),
                    "clicked", G_CALLBACK(on_cancel),NULL);
    gtk_widget_show(dialog);
    
}

/**
 * @Author: 邓方晴
 * @Description: 在输入为空的情况下点击发送键
 * @Param: 
 * @Return: 
 * @Throw: 
 */
void on_input_null()
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(NULL,
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    "发送内容不能为空！", "title");
    gtk_window_set_title(GTK_WINDOW(dialog), "提示");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

/**
 * @Author: 邓方晴
 * @Description: 发送按钮点击事件：将文本编辑框中的信息传给显示区，编辑框清空，显示区显示内容,目前只能传送文本
 * @Param: 结构体，包括编辑框的缓冲区指针和显示区的缓冲区指针
 * @Return: 
 * @Throw: 
 */
gboolean isconnected = TRUE;

void on_send(GtkButton * button,FromToWin* ftw)
{
    gchar *message;
    gchar* username,*friendname;//用户名/ID
    GtkTextIter start,end,show;
    gchar* report = "~$\0";//report是最终向服务器发送对字符串TODO:需要有全局或局部变量外部接应？

    sprintf(username,"User ");//TODO:此处应有措施传递用户名
    sprintf(friendname,"Friendname ");

    if(isconnected==FALSE)  return;
    getThisTime();//获取发送信息的时间

    gtk_text_buffer_get_bounds(ftw->from,&start,&end);
    message = gtk_text_buffer_get_text(ftw->from,&start,&end,FALSE);
    if(message == NULL || strlen(message) == 0)//当输入空字符时
    {
        on_input_null();
        return;
    }
    gtk_text_buffer_set_text(ftw->from,"",1);//清空输入框
    gtk_text_buffer_get_end_iter(ftw->to,&show);
    /////////////////////////////////////////////聊天窗口界面显示
    gtk_text_buffer_insert(ftw->to,&show,username,-1);
    gtk_text_buffer_get_end_iter(ftw->to,&show);
    gtk_text_buffer_insert(ftw->to,&show,nowtime,-1);
    gtk_text_buffer_insert(ftw->to,&show,"\n",-1);
    gtk_text_buffer_get_end_iter(ftw->to,&show);
    gtk_text_buffer_insert(ftw->to,&end,message,-1);
    gtk_text_buffer_get_end_iter(ftw->to,&show);
    gtk_text_buffer_insert(ftw->to,&show,"\n",-1);

    ////////////////////////合成发送信息/////////////////////////
    //strcat(report,"~$ ");
    string_add(report,nowtime);
    // strcat(report,nowtime);
    // strcat(report,"~$ ");
    // strcat(report,username);
    // strcat(report,"~$ ");
    // strcat(report,friendname);
    // strcat(report,"~$ ");
    // strcat(report,message);
    // strcat(report,"~$END\n");

    gtk_text_buffer_get_end_iter(ftw->to,&show);
    gtk_text_buffer_insert(ftw->to,&show,report,-1);


}

/**
 * @Author: 邓方晴
 * @Description: 创建消息记录窗口
 * @Param: 
 * @Return: GtkWidget指针
 * @Throw: 
**/
void create_log_window(GtkWidget *widget, GdkEvent *event)
{
    GtkWidget *window;
    TextView messagelog;
    GtkWidget *scroll;
    GtkTextIter end;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "历史记录");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    scroll = gtk_scrolled_window_new(NULL,NULL);
    gtk_container_add(GTK_CONTAINER(window), scroll);

    messagelog.view = gtk_text_view_new();
    messagelog.view_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(messagelog.view));
    gtk_text_view_set_editable(messagelog.view,FALSE);
    gtk_text_buffer_get_end_iter(messagelog.view_buffer,&end);//设置历史记录不可以被编辑
    gtk_text_buffer_insert(messagelog.view_buffer,&end,"显示消息记录",-1);

    gtk_container_add(GTK_CONTAINER(scroll),messagelog.view);

    gtk_widget_show_all(window);
}


