#include <stdio.h>

int main()
{
    int N, K, i, ans;
    int A[50];
    while(scanf("%d %d", &N, &K) != EOF) {
        for(i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        for(ans = i = 0; i < N; ++i) {
            if(A[i] && A[i] >= A[K - 1]) {
                ++ans;
            } else {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
