/*
 * @Copyright: CS of BIT
 * @Author: 王可欣
 * @File name: 
 * @Version: 
 * @Date: 2019-08-31 19:08:01 -0700
 * @LastEditTime: 2019-09-04 13:50:07 -0700
 * @LastEditors: 
 * @Description: 
 */
#include "head.h"
#include "callbacks.h"
#include "interface.h"

static GtkWidget* dialog = NULL;
TextView SendText,SeeText;
GtkWidget* CreateSendToolbar (GtkWidget* window);
static gboolean on_drag_drop();
static void ReceiveDrop(GtkWidget *widget, GdkDragContext *context,
        gint x,gint y,GtkSelectionData *data,guint info,guint time,gpointer user_data);
static FromToWin* Card;
//static char SendMessage[1024]; 

/**
 * @Author: 王可欣
 * @Description: 创建聊天窗口
 * @Param: 
 * @Return: 
 */
GtkWidget* CreateTalkWindow(void)
{
 
    GtkWidget* TalkWindow;
    GtkWidget* scrolledwinup,*scrolledwindown;
    GtkWidget* TalkMenuBox;
    GtkWidget* menubar ;
    GtkWidget* toolbar,*buttonbox;
    GtkWidget* SendBtn;
    GtkWidget *hPaned,*vPaned,*cardPaned;
    GtkWidget *mylabelcard,*oppolabelcard;
    GtkWidget *mylabel,*friendlabel;
    ChatWindow* Chat; 

    //TODO:Chat应该在聊天窗口打开时获取聊天双方的ID（char）

    TalkWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(TalkWindow),"完整的应用程序窗口");
    gtk_widget_set_size_request(TalkWindow,800,500);//为了固定窗口的大小，不用defaultset
    gtk_window_set_position(GTK_WINDOW(TalkWindow),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(TalkWindow),10);


    //增设最大的两个分隔栏
    hPaned = gtk_hpaned_new();
    gtk_paned_set_position(hPaned,600);
    vPaned = gtk_vpaned_new();
    gtk_paned_set_position(vPaned,300);
    gtk_paned_add1(GTK_PANED(hPaned), vPaned);
    buttonbox = gtk_hbox_new(FALSE,0);

    //右侧好友资料卡与用户资料卡
    cardPaned = gtk_vbox_new(FALSE,10);
    gtk_paned_add2(GTK_PANED(hPaned),cardPaned);
    mylabelcard = gtk_frame_new("个人资料卡");
    gtk_widget_set_size_request(mylabelcard,150,230);
    gtk_frame_set_label_align(GTK_FRAME(mylabelcard),0.5,0);
    oppolabelcard = gtk_frame_new("好友资料卡");
    gtk_widget_set_size_request(oppolabelcard,150,230);
    gtk_frame_set_label_align(GTK_FRAME(oppolabelcard),0.5,0);
    gtk_box_pack_start(GTK_BOX(cardPaned),oppolabelcard,FALSE,FALSE,0);
    gtk_box_pack_end(GTK_BOX(cardPaned),mylabelcard,FALSE,FALSE,0);
    gtk_frame_set_shadow_type(GTK_FRAME(oppolabelcard),GTK_SHADOW_ETCHED_OUT);
    gtk_frame_set_shadow_type(GTK_FRAME(mylabelcard),GTK_SHADOW_ETCHED_OUT);
    mylabel = gtk_label_new("ID: \nIP: \n状态：　在线\n");
    gtk_container_add(GTK_CONTAINER(mylabelcard),mylabel); 
    friendlabel = gtk_label_new("ID: \nIP: \n状态：　在线\n");
    gtk_container_add(GTK_CONTAINER(oppolabelcard),friendlabel);

    /////////////////////TODO:绑定资料卡显示页///////////////////////////////
    // Card->from = mylabelcard.view_buffer;
    // Card->to = oppolabelcard.view_buffer;
    
    TalkMenuBox = gtk_vbox_new(FALSE,0);
    gtk_paned_add2(GTK_PANED(vPaned),TalkMenuBox);
    
    toolbar = CreateSendToolbar(TalkWindow);
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),toolbar,0,1,0);

    scrolledwinup = gtk_scrolled_window_new(NULL,NULL);
    scrolledwindown = gtk_scrolled_window_new(NULL,NULL);

    GtkTextTagTable* tagtableshare = gtk_text_tag_table_new();
    SendText.view_buffer = gtk_text_buffer_new(tagtableshare);
    SendText.view = gtk_text_view_new_with_buffer(SendText.view_buffer);
    SeeText.view_buffer = gtk_text_buffer_new(tagtableshare);
    SeeText.view = gtk_text_view_new_with_buffer(SeeText.view_buffer);

    // //创建指针保存聊天信息编辑窗口和显示窗口的位置
    FromToWin *chatwin= (FromToWin *)malloc(sizeof(FromToWin));
    chatwin->from = SendText.view_buffer;
    chatwin->to = SeeText.view_buffer;
    chatwin->edit = SendText.view;
    chatwin->show = SeeText.view;


    //左下，发送表情与文件的工具栏、文本编辑窗口、发送按钮
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),scrolledwindown,TRUE,TRUE,0);
    gtk_container_add(GTK_CONTAINER(scrolledwindown),SendText.view);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(SendText.view),TRUE);
    gtk_paned_add1(GTK_PANED(vPaned),scrolledwinup);
    gtk_container_add(GTK_CONTAINER(scrolledwinup),SeeText.view);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(SeeText.view),FALSE);
    gtk_text_view_set_cursor_visible(SeeText.view,FALSE);

    //设置消息显示窗口中文本的字体颜色
    gtk_text_buffer_create_tag(SeeText.view_buffer,"AutoWrap","wrap_mode",GTK_WRAP_WORD,NULL);//自动换行
    gtk_text_buffer_create_tag(SeeText.view_buffer,"BLUE","foreground", "blue", NULL);//创建蓝色前景标记
    gtk_text_buffer_create_tag(SeeText.view_buffer,"GREEN","foreground", "green", NULL);//创建蓝色前景标记


    // //拖拽
    GtkTargetEntry targets={"text/uri-list", GTK_TARGET_OTHER_APP,1 };    
    gtk_drag_dest_set(SendText.view, GTK_DEST_DEFAULT_DROP, &targets,1, GDK_ACTION_COPY);   
    g_signal_connect(G_OBJECT(SendText.view),"drag-data-received",G_CALLBACK(ReceiveDrop),NULL);    
    g_signal_connect(G_OBJECT(SendText.view),"drag-drop",G_CALLBACK(on_drag_drop),NULL);

    //左下，发送表情与文件的工具栏、文本编辑窗口、发送按钮
    buttonbox = gtk_hbox_new(FALSE,5);
    gtk_box_pack_start(GTK_BOX(TalkMenuBox),buttonbox,FALSE,FALSE,0);
    SendBtn=gtk_button_new_with_label("发送");
    g_signal_connect(G_OBJECT(SendBtn),"clicked",G_CALLBACK(on_send),(gpointer)chatwin);
    gtk_box_pack_end(buttonbox,SendBtn,FALSE,FALSE,0); 

    gtk_container_add(GTK_CONTAINER(TalkWindow), hPaned);

    gtk_window_set_resizable(GTK_CONTAINER(TalkWindow),FALSE);//固定窗口的大小

    gtk_widget_show_all(TalkWindow);
    return TalkWindow;
}

/**
 * @Author: 王可欣
 * @Description: 创建一个toolbar
 *              表情包、发送文件、聊天记录
 * @Param: 
 * @Return: 
 */
GtkWidget* CreateSendToolbar (GtkWidget* window)
{
    
    GtkWidget* toolbar;
    GtkWidget *StickerIcon,*DocuIcon,*RecIcon;
    GtkWidget* sticker;
    GtkWidget* record;
	GtkToolItem *OpenDocu;

    toolbar = gtk_toolbar_new();
    StickerIcon = gtk_image_new_from_file("./bin/pic/pic.png");
    DocuIcon=gtk_image_new_from_file("./bin/pic/document.png");
    RecIcon=gtk_image_new_from_file("./bin/pic/record.png");
	gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
 
    sticker=gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "", "发送表情", "Private", StickerIcon, 
                                                        GTK_SIGNAL_FUNC (PressStickerBtn), &SendText);
    OpenDocu=gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "", "打开文件", "Private", DocuIcon, 
                                                        GTK_SIGNAL_FUNC (on_file_open_activate), NULL);
    record=gtk_toolbar_append_item (GTK_TOOLBAR (toolbar), "", "消息记录", "Private", RecIcon, 
                                                        GTK_SIGNAL_FUNC (create_log_window), NULL);                               
    return toolbar;
}


/**
 * @Author: 王可欣
 * @Description: 防止on_drag_data_received调用两次
 * @Param: 
 * @Return: 
 */
static gboolean on_drag_drop()
{    
    return TRUE;
}

/**
 * @Author: 王可欣
 * @Description: 识别拖拽进来的文件
 * @Param: 
 * @Return: 
 */
static void ReceiveDrop(GtkWidget *widget, GdkDragContext *context,
        gint x,gint y,GtkSelectionData *data,guint info,guint time,gpointer user_data)
{    
    GdkAtom atom=gtk_selection_data_get_data_type(data);    
    if(gtk_targets_include_uri(&atom,1))
    {        
        gchar **uris=gtk_selection_data_get_uris(data);       
        gint i=0;        
        while(uris[i]!=NULL||uris[i]!='\0')
        {            
            //文件储存地址
            g_printf("%s\n",uris[i]);            
            i++;        
        }        
        g_strfreev(uris);    
    }    
    gtk_drag_finish(context,TRUE,TRUE,time);
}
