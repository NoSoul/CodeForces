#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int value;
} Node_t;
Node_t A[200];

int cmp1(const void *a, const void *b)
{
    return (*(Node_t *)b).value - (*(Node_t *)a).value;
}

int cmp2(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, K, i, j, k, Max = -10000;
    int Data[200], Cur[200];
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Data[i]);
        A[i].id = i;
        A[i].value = Data[i];
    }
    qsort(A, N, sizeof(Node_t), cmp1);
    for(i = 0; i < N; ++i) {
        for(j = i; j < N; ++j) {
            int sum = 0;
            for(k = i; k <= j; ++k) {
                Cur[k - i] = Data[k];
                sum += Data[k];
            }
            qsort(Cur, j - i + 1, sizeof(int), cmp2);
            int cnt = 0;
            int ii = 0;
            int jj = 0;
            while(1) {
                while(A[jj].id >= i && A[jj].id <= j && jj < N) {
                    ++jj;
                }
                if(jj == N) {
                    break;
                }
                while(Cur[ii] >= A[jj].value && ii < j - i + 1) {
                    ++ii;
                }
                if(ii == j - i + 1) {
                    break;
                }
                sum -= Cur[ii];
                Cur[ii] = A[jj].value;
                sum += Cur[ii];
                ++ii;
                ++jj;
                if(++cnt == K) {
                    break;
                }
            }
            if(sum > Max) {
                Max = sum;
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
