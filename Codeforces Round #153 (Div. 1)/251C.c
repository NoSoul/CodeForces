#include <stdio.h>

int A[100001];
int Ans[100001];

int main()
{
    int N, K, i, j, Min, Mini;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = j = 1; i < N; ++i) {
        if(A[i] != A[j - 1]) {
            A[j++] = A[i];
        }
    }
    N = j;
    for(i = 0; i < N; ++i) {
        if(i == 0 || i == N - 1) {
            ++Ans[A[i]];
        } else {
            if(A[i - 1] != A[i + 1]) {
                ++Ans[A[i]];
            } else {
                Ans[A[i]] += 2;
            }
        }
    }
    Min = 0;
    for(i = 1; i <= K; ++i) {
        if(Ans[i] > Min) {
            Min = Ans[i];
            Mini = i;
        }
    }
    printf("%d\n", Mini);
    return 0;
}
