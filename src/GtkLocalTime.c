/*
 * @Copyright: CS of BIT
 * @Author: 邓方晴
 * @File name: GtkLocalTime.c
 * @Version: 
 * @Date: 2019-09-01 18:12:42 -0700
 * @LastEditTime: 2019-09-02 01:08:55 -0700
 * @LastEditors: 
 * @Description: 调取系统时间，与系统时间有关的操作在此处进行
 */

#include "head.h"

/**
 * @Author: 邓方晴
 * @Description: 获取当前时间，返回 “年/月/日 小时：分钟：秒”格式的字符串首地址
 * @Param: 无
 * @Return: char指针（字符串首地址）
 * @Throw: 获取系统时间失败、返回字符串地址失败
 */
// GString getLocalTime()
// {
//     time_t now ;
//     //char nowtime[30];
//     char tmp[30];
//     GString nowtime;
//     struct tm *l_time;
//     printf("local time is called\n");
//     now = time((time_t *)NULL);
//     l_time = localtime(&now); //取本地时间
//     //memset(nowtime,'\0',sizeof(nowtime));
//     sprintf(tmp,"%d/%d/%d  %d:%d:%d",l_time->tm_year+1900,l_time->tm_mon+1,l_time->tm_mday,l_time->tm_hour,l_time->tm_min,l_time->tm_sec);
//     g_string_assign(nowtime,gchar(tmp));
//     printf("time in func is : %s\n",nowtime);
//     return nowtime;
// }
