#include <stdio.h>

int main()
{
    int N, M, k, m, i, Num;
    int A, B;
    scanf("%d %d %d %d", &N, &M, &k, &m);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        if(i == k - 1) {
            A = Num;
        }
    }
    for(i = 0; i < M; ++i) {
        scanf("%d", &Num);
        if(i == M - m) {
            B = Num;
        }
    }
    puts(A < B ? "YES" : "NO");
    return 0;
}
