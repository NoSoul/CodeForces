#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x,y;
} Point_t;
Point_t P[100000];

int cmp(const void *a,const void *b)
{
    if(abs((*(Point_t*)a).x)==abs((*(Point_t*)b).x))
    {
        return abs((*(Point_t*)a).y)-abs((*(Point_t*)b).y);
    }
    return abs((*(Point_t*)a).x)-abs((*(Point_t*)b).x);
}

int main()
{
    int N,i,Sum,now;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d %d",&P[i].x,&P[i].y);
    }
    qsort(P,N,sizeof(Point_t),cmp);
    for(Sum=i=0; i<N; ++i)
    {
        now=2;
        if(P[i].x==0||P[i].y==0)
        {
            now=1;
        }
        Sum+=now*2+2;
    }
    printf("%d\n",Sum);
    for(i=0; i<N; ++i)
    {
        if(P[i].x!=0)
        {
            printf("1 %d %c\n",abs(P[i].x),P[i].x<0?'L':'R');
        }
        if(P[i].y!=0)
        {
            printf("1 %d %c\n",abs(P[i].y),P[i].y<0?'D':'U');
        }
        printf("2\n");
        if(P[i].y!=0)
        {
            printf("1 %d %c\n",abs(P[i].y),P[i].y<0?'U':'D');
        }
        if(P[i].x!=0)
        {
            printf("1 %d %c\n",abs(P[i].x),P[i].x<0?'R':'L');
        }
        printf("3\n");
    }
    return 0;
}
