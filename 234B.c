#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data,index;
} Node;
Node A[1002];

int cmp(const void *a,const void *b)
{
    if((*(Node *)a).data==(*(Node *)b).data)
    {
        return (*(Node *)a).index-(*(Node *)b).index;
    }
    return (*(Node *)b).data-(*(Node *)a).data;
}

int cmp2(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int N,K,i;
    int R[1002];
    scanf("%d %d",&N,&K);
    for(i=1; i<=N; ++i)
    {
        A[i].index=i;
        scanf("%d",&A[i].data);
    }
    qsort(A+1,N,sizeof(Node),cmp);
    for(i=1; i<=K; ++i)
    {
        R[i]=A[i].index;
    }
    qsort(R+1,K,sizeof(int),cmp2);
    printf("%d\n",A[K].data);
    for(i=1; i<K; ++i)
    {
        printf("%d ",R[i]);
    }
    printf("%d\n",R[i]);
    return 0;
}
