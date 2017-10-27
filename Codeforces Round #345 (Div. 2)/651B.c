#include <stdio.h>

int A[1001];

int main()
{
    int N, i, Num, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        ++A[Num];
    }
    while(N) {
        int cur = 0;
        for(i = 1; i < 1001; ++i) {
            if(A[i]) {
                --A[i];
                ++cur;
                --N;
            }
        }
        Ans += cur - 1;
    }
    printf("%d\n", Ans);
    return 0;
}
