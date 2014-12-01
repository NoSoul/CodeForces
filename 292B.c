#include <stdio.h>
#include <stdlib.h>

int Visit[100001];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int IsBus(int *v, int n)
{
    if(v[0] == 2 && v[n - 1] == 1 && v[n - 2] == 1 && v[n - 3] == 2)
    {
        return 1;
    }
    return 0;
}

int IsRing(int *v, int n)
{
    if(v[0] == 2 && v[n - 1] == 2)
    {
        return 1;
    }
    return 0;
}

int IsStar(int *v, int n)
{
    if(v[0] >= 3 && v[1] == 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int N, M, a, b;
    scanf("%d %d", &N, &M);
    while(M--)
    {
        scanf("%d %d", &a, &b);
        ++Visit[a - 1];
        ++Visit[b - 1];
    }
    qsort(Visit, N, sizeof(int), cmp);
    if(IsBus(Visit, N))
    {
        puts("bus topology");
    }
    else if(IsRing(Visit, N))
    {
        puts("ring topology");
    }
    else if(IsStar(Visit, N))
    {
        puts("star topology");
    }
    else
    {
        puts("unknown topology");
    }
    return 0;
}
