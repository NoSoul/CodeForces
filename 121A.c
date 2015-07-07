#include <stdio.h>

int main()
{
    int i, j, k = 0;
    long long A[1024];
    char Str[10];
    long long Sum = 0, l, r;
    for(i = 1; i <= 9; ++i) {
        for(j = 0; j < (1 << i); ++j) {
            l = j;
            r = 0;
            while(l) {
                Str[r++] = l & 1;
                l >>= 1;
            }
            for(; r < i; ++r) {
                Str[r] = 0;
            }
            A[k] = 0;
            for(--r; r >= 0; --r) {
                A[k] *= 10;
                A[k] += Str[r] ? 7 : 4;
            }
            ++k;
        }
    }
    A[k++] = 4444444444LL;
    scanf("%I64d %I64d", &l, &r);
    j = 0;
    Sum = 0;
    while(l <= r) {
        for(i = j; i < k; ++i) {
            if(A[i] >= l) {
                break;
            }
        }
        if(A[i] <= r) {
            Sum += (long long)(A[i] - l + 1) * A[i];
        } else {
            Sum += (long long)(r - l + 1) * A[i];
        }
        l = A[i] + 1;
        j = i + 1;
    }
    printf("%I64d\n", Sum);
    return 0;
}
