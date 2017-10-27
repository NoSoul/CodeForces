#include <stdio.h>

int main()
{
    int i, N, Cnt, Ans;
    int A[1000];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    Cnt = Ans = 0;
    while(1) {
        for(i = 0; i < N; ++i) {
            if(Cnt >= A[i]) {
                A[i] = 0x7fffffff;
                ++Cnt;
            }
        }
        if(Cnt == N) {
            break;
        }
        ++Ans;
        for(i = N - 1; i >= 0; --i) {
            if(Cnt >= A[i]) {
                A[i] = 0x7fffffff;
                ++Cnt;
            }
        }
        if(Cnt == N) {
            break;
        }
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
