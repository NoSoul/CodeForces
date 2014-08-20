#include <stdio.h>

int Judge(char c)
{
    if(c=='a'||c=='o'||c=='y'||c=='e'||c=='u'||c=='i')
    {
        return 0;
    }
    return 1;
}

int main()
{
    int  i;
    char Str[101];
    while(scanf("%s",Str)!=EOF)
    {
        for(i=0; Str[i]!='\0'; ++i)
        {
            if(Str[i]<'a')
            {
                Str[i]=Str[i]-'A'+'a';
            }
            if(Judge(Str[i]))
            {
                printf(".%c",Str[i]);
            }
        }
        puts("");
    }
    return 0;
}
