#include "myhead.h"
char *mygetline()//用来读取一行字符串的函数
{
    char *str;
    str=(char*)malloc(sizeof(char)*100);
    int len=0;
    char ch;
    while((ch=getchar())!='\n' && len<100)
    {
        *(str+(len++))=ch;
    }
    if(len==100)
    {
        printf("Too long input!\n");
        return NULL;
    }
    *(str+len)='\0';
    //printf("%s\n",str);
    return str;
}