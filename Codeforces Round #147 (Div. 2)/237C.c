#include <stdio.h>

#define MAXN 1000034
#define max(a,b) (a)>(b)?(a):(b)

char Flag[MAXN];
int  Prime[79000];
int  Cnt;

void Make()
{
    int i, j;
    for(Cnt = 0, i = 2; i < MAXN; ++i) {
        if(!Flag[i]) {
            Prime[Cnt++] = i;
            for(j = i << 1; j < MAXN; j += i) {
                Flag[j] = 1;
            }
        }
    }
    return;
}

int Binary(int key)
{
    int Left, Mid, Right;
    Left = 0;
    Right = Cnt;
    while(Right >= Left) {
        Mid = (Left + Right) / 2;
        if(Prime[Mid] == key) {
            return Mid;
        } else if(Prime[Mid] < key) {
            Left = Mid + 1;
        } else {
            Right = Mid - 1;
        }
    }
    return Left;
}

int main()
{
    int A, B, K, i, j, k, Max;
    Make();
    while(scanf("%d %d %d", &A, &B, &K) != EOF) {
        j = Binary(A);
        k = Binary(B);
        if(B != Prime[k]) {
            --k;
        }
        if(K > k - j + 1) {
            puts("-1");
            continue;
        }
        Max = Prime[j + K - 1] - A + 1;
        if((B - Prime[k - K + 1] + 1) > Max) {
            Max = B - Prime[k - K + 1] + 1;
        }
        for(i = j; i + K <= k; ++i) {
            if((Prime[i + K] - Prime[i]) > Max) {
                Max = Prime[i + K] - Prime[i];
            }
        }
        printf("%d\n", Max);
    }
    return 0;
}
