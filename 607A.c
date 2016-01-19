#include <stdio.h>
#include <stdlib.h>

#define MAXN        100001

typedef struct {
    int a;
    int b;
} Beacons_t;
Beacons_t B[MAXN];
int Dp[MAXN];

int cmp(const void *a, const void *b)
{
    return (*(Beacons_t*)a).a - (*(Beacons_t*)b).a;
}

int BinarySearch(Beacons_t *array, int len, int key)
{
    int Left, Right, Mid;
    Left = 0;
    Right = len - 1;
    while(Left < Right - 1) {
        Mid = (Left + Right) / 2;
        if(array[Mid].a >= key) {
            Right = Mid - 1;
        } else {
            Left = Mid;
        }
    }
    if(array[Right].a < key) {
        return Right;
    }
    if(array[Left].a >= key) {
        --Left;
    }
    return Left;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &B[i].a, &B[i].b);
    }
    qsort(B, N, sizeof(Beacons_t), cmp);
    Dp[0] = 1;
    for(i = 1; i < N; ++i) {
        int last = BinarySearch(B, N, B[i].a - B[i].b);
        if(last == -1) {
            Dp[i] = Dp[i - 1];
        } else {
            Dp[i] = Dp[last] + 1;
        }
    }
    int Max = 0;
    for(i = 0; i < N; ++i) {
        if(Dp[i] > Max) {
            Max = Dp[i];
        }
    }
    printf("%d\n", N - Max);
    return 0;
}
