#include <stdio.h>
#include <stdlib.h>

int Hash[102];
int A[100];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, Num, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        ++Hash[Num];
    }
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    for(i = 0; i < N; ++i)
    {
        Num = A[i];
        if(Hash[Num - 1])
        {
            ++Ans;
            --Hash[Num - 1];
        }
        else if(Hash[Num])
        {
            ++Ans;
            --Hash[Num];
        }
        else if(Hash[Num + 1])
        {
            ++Ans;
            --Hash[Num + 1];
        }
    }
    printf("%d\n", Ans);
    return 0;
}
