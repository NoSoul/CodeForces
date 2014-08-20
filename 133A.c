#include <stdio.h>

int main()
{
    int  i,flag;
    char Str[101];
    scanf("%s",Str);
    for(flag=i=0; Str[i]!='\0'; ++i)
    {
        if(Str[i]=='H'||Str[i]=='Q'||Str[i]=='9')
        {
            flag=1;
            break;
        }
    }
    puts(flag?"YES":"NO");
    return 0;
}
