#include <stdio.h>

#define MAXN    100001

int A[MAXN];
int Ans[MAXN];

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = N - 1; i >= 0; --i) {
        if(A[i] == N || Ans[A[i] + 1] == 0) {
            Ans[A[i]] = 1;
        } else {
            Ans[A[i]] = Ans[A[i] + 1] + 1;
        }
    }
    int Max = Ans[1];
    for(i = 1; i <= N; ++i) {
        if(Ans[i] > Max) {
            Max = Ans[i];
        }
    }
    printf("%d\n", N - Max);
    return 0;
}
