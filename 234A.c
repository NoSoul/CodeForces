#include <stdio.h>

int N;
char Str[102];

void Check(int i,int j)
{
    if(Str[i]!=Str[j]&&Str[i]=='R'&&Str[j]=='L')
    {
        printf("%d %d\n",j,i);
    }
    else
    {
        printf("%d %d\n",i,j);
    }
    return;
}

void Solve(int N)
{
    int i;
    for(i=1; i<=N; i+=4)
    {
        Check(i,i+2);
        Check(i+1,i+3);
    }
    return;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,M;
    scanf("%d",&N);
    scanf("%s",Str+1);
    M=N/2;
    if(M%2)
    {
        Solve(N-6);
        i=N-5;
        Check(i,i+3);
        Check(i+1,i+4);
        Check(i+2,i+5);
    }
    else
    {
        Solve(N);
    }
    return 0;
}
