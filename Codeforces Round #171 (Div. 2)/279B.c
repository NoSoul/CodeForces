#include <stdio.h>

int A[100001];
int Sum[100001];

int Binary(int s, int e, int key)
{
    int Left, Right, Mid;
    Left = s;
    Right = e;
    while(Right > Left) {
        Mid = (Right + Left) / 2;
        if(Sum[Mid] - Sum[s] == key) {
            return Mid;
        } else if(Sum[Mid] - Sum[s] > key) {
            Right = Mid - 1;
        } else {
            Left = Mid + 1;
        }
    }
    if(Sum[Left] - Sum[s] > key) {
        --Left;
    }
    return Left;
}

int main()
{
    int T, N, i, Max, Now;
    scanf("%d %d", &N, &T);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        Sum[i] += Sum[i - 1] + A[i];
    }
    for(Max = 0, i = 1; i <= N; ++i) {
        if(T >= A[i]) {
            Now = Binary(i, N, T - A[i]) - i + 1;
            if(Max < Now) {
                Max = Now;
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
