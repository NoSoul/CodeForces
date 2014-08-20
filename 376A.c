#include <stdio.h>

char Str[1000001];

int main()
{
    int i,mid;
    long long Left,Right;
    scanf("%s",&Str);
    for(i=0; Str[i]!='\0'&&Str[i]!='^'; ++i);
    mid=i;
    for(Left=0,i=0; i<mid; ++i)
    {
        if(Str[i]!='=')
        {
            Left+=(long long)(mid-i)*(Str[i]-'0');
        }
    }
    for(Right=0,i=mid+1; Str[i]!='\0'; ++i)
    {
        if(Str[i]!='=')
        {
            Right+=(long long)(i-mid)*(Str[i]-'0');
        }
    }
    puts(Left==Right?"balance":(Left<Right?"right":"left"));
    return 0;
}
