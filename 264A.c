#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN    1000001
typedef struct
{
    int id;
    int pos;
} Stone_t;
Stone_t Ans[MAXN];

int cmp(const void *a, const void *b)
{
    return (*(Stone_t *)a).pos - (*(Stone_t *)b).pos;
}

int main()
{
    int i, N;
    int l, r;
    char Str[MAXN];
    scanf("%s", Str);
    N = strlen(Str);
    l = 1;
    r = N;
    for(i=0; Str[i]!='\0'; ++i)
    {
        Ans[i].id = i+1;
        if(Str[i] == 'l')
        {
            Ans[i].pos = r;
            --r;
        }
        else
        {
            Ans[i].pos = l;
            ++l;
        }
    }
    qsort(Ans, N, sizeof(Stone_t), cmp);
    for(i=0; i<N; ++i)
    {
        printf("%d\n", Ans[i].id);
    }
    return 0;
}
