#include <stdio.h>

int Get(int n)
{
    return (long long)n * (n + 1) / 2;
}

int A[100000];

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 1; i <= N; ++i) {
        if(K > Get(i - 1) && K <= Get(i)) {
            K -= Get(i - 1) + 1;
            printf("%d\n", A[K]);
            break;
        }
    }
    return 0;
}
