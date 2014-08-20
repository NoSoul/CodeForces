#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x,y;
} Dragon;
Dragon D[1001];

int cmp(const void *a,const void *b)
{
    return (*(Dragon *)a).x-(*(Dragon *)b).x;
}

int main()
{
    int S,N,i;
    scanf("%d %d",&S,&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d %d",&D[i].x,&D[i].y);
    }
    qsort(D,N,sizeof(Dragon),cmp);
    for(i=0; i<N; ++i)
    {
        if(S<=D[i].x)
        {
            break;
        }
        S+=D[i].y;
    }
    puts(i<N?"NO":"YES");
    return 0;
}
