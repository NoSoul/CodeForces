#include <stdio.h>

int A[200000];

int main()
{
    int N, t, c, i, sum, Ans;
    scanf("%d %d %d", &N, &t, &c);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(Ans = sum = i = 0; i < N; ++i) {
        if(A[i] <= t) {
            if(++sum >= c) {
                ++Ans;
            }
        } else {
            sum = 0;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
