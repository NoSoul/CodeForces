#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char Str[33];
    int index,num;
} Node;
Node Data[100000];

int cmp1(const void *a,const void *b)
{
    if(strcmp((*(Node *)a).Str,(*(Node *)b).Str)==0)
    {
        return (*(Node *)a).index-(*(Node *)b).index;
    }
    return strcmp((*(Node *)a).Str,(*(Node *)b).Str);
}

int cmp2(const void *a,const void *b)
{
    return (*(Node *)a).index-(*(Node *)b).index;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%s",Data[i].Str);
        Data[i].index=i;
    }
    qsort(Data,N,sizeof(Node),cmp1);
    Data[0].num=0;
    for(i=1; i<N; ++i)
    {
        if(strcmp(Data[i].Str,Data[i-1].Str)==0)
        {
            Data[i].num=Data[i-1].num+1;
        }
        else
        {
            Data[i].num=0;
        }
    }
    qsort(Data,N,sizeof(Node),cmp2);
    for(i=0; i<N; ++i)
    {
        if(Data[i].num==0)
        {
            printf("OK\n");
        }
        else
        {
            printf("%s%d\n",Data[i].Str,Data[i].num);
        }
    }
    return 0;
}
