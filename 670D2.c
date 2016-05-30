#include <stdio.h>

#define MAXN    100000

int A[MAXN];
int B[MAXN];

long long Need(int N, long long num)
{
    long long ret = 0;
    for(int i = 0; i < N; ++i) {
        if(num * A[i] > B[i]) {
            ret += num * A[i] - B[i];
        }
    }
    return ret;
}

int main()
{
    int N, K, i;
    long long sumA = 0, sumB = 0;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        sumA += A[i];
    }
    for(i = 0; i < N; ++i) {
        scanf("%d", &B[i]);
        sumB += B[i];
    }
    long long left = 0;
    long long right = (K + sumB) / sumA;
    while(left < right - 1) {
        long long mid = (left + right) / 2;
        long long need = Need(N, mid);
        if(need > K) {
            right = mid - 1;
        } else {
            left = mid;
        }
    }
    for(++right; right >= 0; --right) {
        if(K >= Need(N, right)) {
            printf("%I64d\n", right);
            break;
        }
    }
    return 0;
}
