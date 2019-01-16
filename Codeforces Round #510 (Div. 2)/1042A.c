#include <stdio.h>

int main()
{
    int n, m, mPrime, max = 0;
    int A[100];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        if(max < A[i]) {
            max = A[i];
        }
    }
    mPrime = m;
    int delta = 0;
    for(int i = 0; i < n; ++i) {
        delta += max - A[i];
    }
    if(delta >= m) {
        m = 0;
    } else {
        m -= delta;
    }
    printf("%d %d\n", max + (m + n - 1) / n, max + mPrime);
    return 0;
}
