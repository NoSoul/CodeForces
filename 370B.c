#include <stdio.h>
#include <string.h>

typedef struct
{
    int m;
    int A[100];
} Player_t;
Player_t Data[100];
char Flag[100];
char NumInA[101];
char NumInB[101];

int main()
{
    int N,i,j,k;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d",&Data[i].m);
        for(j=0; j<Data[i].m; ++j)
        {
            scanf("%d",&Data[i].A[j]);
        }
    }
    for(i=0; i<N; ++i)
    {
        memset(NumInA,0,sizeof(NumInA));
        for(k=0; k<Data[i].m; ++k)
        {
            NumInA[Data[i].A[k]]=1;
        }
        for(j=0; j<N; ++j)
        {
            if(i!=j&&Data[j].m<=Data[i].m)
            {
                memset(NumInB,0,sizeof(NumInB));
                for(k=0; k<Data[j].m; ++k)
                {
                    NumInB[Data[j].A[k]]=1;
                }
                for(k=0; k<101; ++k)
                {
                    if(NumInB[k]&&!NumInA[k])
                    {
                        break;
                    }
                }
                if(k==101)
                {
                    Flag[i]=1;
                    break;
                }
            }
        }
    }
    for(i=0; i<N; ++i)
    {
        puts(Flag[i]?"NO":"YES");
    }
    return 0;
}
