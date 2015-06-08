#include <stdio.h>

typedef long long LL_t;

int main()
{
    LL_t N, M, r, min, max;
    scanf("%I64d %I64d", &N, &M);
    r = N - M;
    if(r & 1) {
        max = (r + 1) / 2 * r;
    } else {
        max = r / 2 * (r + 1);
    }
    if((r / M) & 1) {
        min = (1 + r / M) / 2 * (2 + r / M) * (r % M) + (1 + r / M) / 2 * (r / M) * (M - r % M);
    } else {
        min = (2 + r / M) / 2 * (1 + r / M) * (r % M) + (r / M) / 2 * (1 + r / M) * (M - r % M);
    }
    printf("%I64d %I64d\n", min, max);
    return 0;
}
