#include <stdio.h>
#include <string.h>

typedef struct {
    int bitMask[64];
} Node_t;

void Add(Node_t *a, long long num)
{
    int i = 0;
    while(num) {
        a->bitMask[i++] += num & 1;
        num >>= 1;
    }
}

void Sub(Node_t *a, long long num)
{
    int i = 0;
    while(num) {
        a->bitMask[i++] -= num & 1;
        num >>= 1;
    }
}

void Get(Node_t *a, long long *num)
{
    int i;
    *num = 0;
    for(i = 63; i >= 0; --i) {
        *num <<= 1;
        *num |= (a->bitMask[i] ? 1 : 0);
    }
}

long long A[200000];

int main()
{
    int N, k, x, i, j;
    Node_t cur, sum;
    long long originSum, tempSum;
    memset(&sum, 0, sizeof(Node_t));
    scanf("%d %d %d", &N, &k, &x);
    for(i = 0; i < N; ++i) {
        scanf("%I64d", &A[i]);
        Add(&sum, A[i]);
    }
    Get(&sum, &originSum);
    for(i = 0; i < N; ++i) {
        if(A[i] == 0) {
            continue;
        }
        memcpy(&cur, &sum, sizeof(Node_t));
        Sub(&cur, A[i]);
        for(j = 0; j < k; ++j) {
            A[i] *= x;
        }
        Add(&cur, A[i]);
        Get(&cur, &tempSum);
        if(tempSum > originSum) {
            originSum = tempSum;
        }
    }
    printf("%I64d\n", originSum);
    return 0;
}
