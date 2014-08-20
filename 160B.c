#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(char *)a>*(char *)b?1:-1;
}

int main()
{
    int  N,i;
    char Str[201];
    scanf("%d %s",&N,Str);
    qsort(Str,N,sizeof(char),cmp);
    qsort(Str+N,N,sizeof(char),cmp);
    if(Str[0]==Str[N])
    {
        puts("NO");
        return 0;
    }
    for(i=1; i<N; ++i)
    {
        if(!((Str[i-1]>Str[N+i-1]&&Str[i]>Str[N+i])||(Str[i-1]<Str[N+i-1]&&Str[i]<Str[N+i])))
        {
            break;
        }
    }
    puts(i==N?"YES":"NO");
    return 0;
}
