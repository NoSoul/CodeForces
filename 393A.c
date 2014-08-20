#include <stdio.h>

int Hash[26];

int main()
{
    int i,Res;
    char Str[101];
    scanf("%s",Str);
    for(i=0; Str[i]!='\0'; ++i)
    {
        ++Hash[Str[i]-'a'];
    }
    Res=0;
    while(1)
    {
        if(Hash['e'-'a']>=3&&Hash['i'-'a']>=1&&Hash['n'-'a']>=3&&Hash['t'-'a']>=1)
        {
            Hash['e'-'a']-=3;
            Hash['i'-'a']-=1;
            Hash['n'-'a']-=2;
            Hash['t'-'a']-=1;
            ++Res;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",Res);
    return 0;
}
