#include <stdio.h>

int main()
{
    int N,M,i,j,num,Ans;
    scanf("%d %d",&N,&M);
    Ans=4;
    for(i=0; i<N; ++i)
    {
        for(j=0; j<M; ++j)
        {
            scanf("%d",&num);
            if(num==1&&(i==0||j==0||i==N-1||j==M-1))
            {
                Ans=2;
            }
        }
    }
    printf("%d\n",Ans);
    return 0;
}
