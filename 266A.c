#include <stdio.h>

int main()
{
    int N,i,Cnt;
    char Str[51];
    scanf("%d %s",&N,Str);
    for(Cnt=i=0; Str[i+1]!='\0'; ++i)
    {
        if(Str[i]==Str[i+1])
        {
            ++Cnt;
        }
    }
    printf("%d\n",Cnt);
    return 0;
}
