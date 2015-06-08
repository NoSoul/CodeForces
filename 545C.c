#include <stdio.h>

typedef struct {
    int x, h;
} Node_t;
Node_t A[100000];

int main()
{
    int N, i, Bound, Ans = 1;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].x, &A[i].h);
    }
    Bound = A[0].x;
    for(i = 1; i < N - 1; ++i) {
        if(A[i].x - A[i].h <= Bound) {
            if( A[i].x + A[i].h < A[i + 1].x) {
                ++Ans;
                Bound = A[i].x + A[i].h;
            } else {
                Bound = A[i].x;
            }
        } else {
            ++Ans;
            Bound = A[i].x;
        }
    }
    if(Bound < A[N - 1].x) {
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
