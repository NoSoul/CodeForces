#include <stdio.h>

int Hash[26],Unknow;

int main()
{
    int i,j,Sum;
    char Type;
    char Str[100001];
    scanf("%s",Str);
    if(!(Str[0]>='1'&&Str[0]<='9'))
    {
        if(Str[0]=='?')
        {
            Type=1;
            Sum=9;
        }
        else
        {
            Type=2;
            Sum=9;
        }
    }
    else
    {
        Type=3;
        Sum=1;
    }
    for(i=1; Str[i]!='\0'; ++i)
    {
        if(Str[i]>='A'&&Str[i]<='J')
        {
            ++Hash[Str[i]-'A'];
        }
        if(Str[i]=='?')
        {
            ++Unknow;
        }
    }
    if(Type==1)
    {
        j=10;
    }
    else if(Type==2)
    {
        j=9;
        Hash[Str[0]-'A']=0;
    }
    else if(Type==3)
    {
        j=10;
    }
    for(i=0; i<10; ++i)
    {
        if(Hash[i])
        {
            Sum*=j;
            --j;
        }
    }
    printf("%d",Sum);
    while(Unknow--)
    {
        printf("0");
    }
    printf("\n");
    return 0;
}

