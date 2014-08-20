#include <stdio.h>

char Str[100002];
int Cnt[3][100002];

int main()
{
    int i,M,l,r,max,min;
    scanf("%s",Str+1);
    for(i=1; Str[i]!='\0'; ++i)
    {
        Cnt[0][i]=Cnt[0][i-1]+(Str[i]=='x');
        Cnt[1][i]=Cnt[1][i-1]+(Str[i]=='y');
        Cnt[2][i]=Cnt[2][i-1]+(Str[i]=='z');
    }
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d %d",&l,&r);
        min=0x7fffffff;
        max=0;
        for(i=0; i<3; ++i)
        {
            int now=Cnt[i][r]-Cnt[i][l-1];
            max=max>now?max:now;
            min=min<now?min:now;
        }
        puts((r-l)<2||(max-min)<2?"YES":"NO");
    }
    return 0;
}
