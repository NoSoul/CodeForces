#include <stdio.h>

int main()
{
    int i,Cnt_4,Cnt_7;
    char Str[51];
    scanf("%s",Str);
    for(Cnt_4=Cnt_7=i=0; Str[i]!='\0'; ++i)
    {
        if(Str[i]=='4')
        {
            ++Cnt_4;
        }
        if(Str[i]=='7')
        {
            ++Cnt_7;
        }
    }
    if(Cnt_4==Cnt_7&&Cnt_4==0)
    {
        puts("-1");
        return 0;
    }
    puts(Cnt_4>=Cnt_7?"4":"7");
    return 0;
}
