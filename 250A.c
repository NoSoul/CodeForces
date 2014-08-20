#include <stdio.h>

int main()
{
    int N,i,Len,Cnt,j,num;
    int Ans[40];
    scanf("%d",&N);
    for(j=Cnt=Len=i=0; i<N; ++i)
    {
        scanf("%d",&num);
        if(num<0)
        {
            ++Cnt;
        }
        if(Cnt==3)
        {
            Ans[j++]=Len;
            Cnt=1;
            Len=1;
            continue;
        }
        Len++;
    }
    Ans[j++]=Len;
    printf("%d\n",j);
    for(i=0; i<j; ++i)
    {
        printf("%d ",Ans[i]);
    }
    return 0;
}
