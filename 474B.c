#include <stdio.h>

int Hash[1000001];

int main()
{
    int N, i, j, Pre, Num;
    scanf("%d", &N);
    Pre = 1;
    for(i=1; i<=N; ++i)
    {
        scanf("%d", &Num);
        for(j=Pre; j<Pre+Num; ++j)
        {
            Hash[j] = i;
        }
        Pre += Num;
    }
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d", &Num);
        printf("%d\n", Hash[Num]);
    }
    return 0;
}
