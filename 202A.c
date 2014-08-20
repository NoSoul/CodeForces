#include <stdio.h>

char Flag[26];

int main()
{
    int  i,N;
    char Str[11];
    scanf("%s",Str);
    for(i=0; Str[i]!='\0'; ++i)
    {
        ++Flag[Str[i]-'a'];
    }
    for(i=25; i>=0; --i)
    {
        if(Flag[i])
        {
            break;
        }
    }
    while(Flag[i]--)
    {
        printf("%c",i+'a');
    }
    printf("\n");
    return 0;
}
