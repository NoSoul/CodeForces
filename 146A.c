#include <stdio.h>

#define  MAX 51

int main()
{
    int i,j,N,A,B;
    char Str[MAX];
    scanf("%d %s",&N,Str);
    for(i=0; i<N; ++i)
    {
        if(Str[i]!='4'&&Str[i]!='7')
        {
            break;
        }
    }
    if(i<N)
    {
        puts("NO");
        return 0;
    }
    for(A=B=i=0,j=N-1; j>i; ++i,--j)
    {
        A+=Str[i]-'0';
        B+=Str[j]-'0';
    }
    puts(A==B?"YES":"NO");
    return 0;
}
