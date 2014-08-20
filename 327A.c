#include <stdio.h>

char Src[101];

int main()
{
    int N,i,j,k,Cnt,Max;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&Src[i]);
    }
    for(Max=i=0; i<N; ++i)
    {
        for(j=i; j<N; ++j)
        {
            for(k=i; k<=j; ++k)
            {
                Src[k]^=1;
            }
            for(Cnt=k=0; k<N; ++k)
            {
                Cnt+=Src[k];
            }
            if(Cnt>Max)
            {
                Max=Cnt;
            }
            for(k=i; k<=j; ++k)
            {
                Src[k]^=1;
            }
        }
    }
    printf("%d\n",Max);
    return 0;
}
