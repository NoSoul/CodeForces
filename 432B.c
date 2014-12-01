#include <stdio.h>

typedef struct
{
    int x, y;
} Team_t;
Team_t T[100001];

int HashX[100001];
int HashY[100001];

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &T[i].x, &T[i].y);
        ++HashX[T[i].x];
        ++HashY[T[i].y];
    }
    for(i = 0; i < N; ++i)
    {
        j = N - 1 - HashX[T[i].y];
        printf("%d %d\n", N + N - 2 - j, j);
    }
    return 0;
}
