#include <stdio.h>

int A[100001];

int main()
{
    int N, K, i, flag;
    scanf("%d %d", &N, &K);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    for(flag = 1, i = K + 1; i <= N; ++i) {
        if(A[i] != A[i - 1]) {
            flag = 0;
            break;
        }
    }
    if(flag == 0) {
        printf("-1\n");
    } else {
        while(K != 1 && A[K] == A[K - 1]) {
            --K;
        }
        printf("%d\n", K - 1);
    }
    return 0;
}
