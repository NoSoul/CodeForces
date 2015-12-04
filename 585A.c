#include <stdio.h>

#define MAXN    1000001

typedef struct {
    int v, d, p;
} Node_t;
Node_t A[4000];
int Ans[4000];
int Size;

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d %d %d", &A[i].v, &A[i].d, &A[i].p);
    }
    for(i = 0; i < N; ++i) {
        if(A[i].p >= 0 && A[i].p < MAXN) {
            Ans[Size++] = i;
            int val = A[i].v;
            for(j = i + 1; j < N; ++j) {
                if(A[j].p >= 0 && A[j].p < MAXN) {
                    A[j].p -= val;
                    if(--val == 0) {
                        break;
                    }
                }
            }
            long long Sum = 0;
            for(j = i + 1; j < N; ++j) {
                if(A[j].p != MAXN) {
                    if(A[j].p >= Sum) {
                        A[j].p -= Sum;
                    } else {
                        A[j].p = -1;
                    }
                }
                if(A[j].p < 0) {
                    A[j].p = MAXN;
                    Sum += A[j].d;
                }
            }
        }
    }
    printf("%d\n", Size);
    for(i = 0; i < Size; ++i) {
        printf("%d ", Ans[i] + 1);
    }
    puts("");
    return 0;
}
