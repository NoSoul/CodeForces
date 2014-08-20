#include <stdio.h>
#include <string.h>

int main()
{
    int Cnt,i,Sum,Len;
    char Str[101];
    Cnt=Sum=0;
    while(gets(Str)!=NULL)
    {
        if(Str[0]=='+')
        {
            ++Cnt;
        }
        else if(Str[0]=='-')
        {
            --Cnt;
        }
        else
        {
            Len=strlen(Str);
            for(i=0; Str[i]!=':'; ++i);
            Sum+=(Len-i-1)*Cnt;
        }
    }
    printf("%d\n",Sum);
    return 0;
}
