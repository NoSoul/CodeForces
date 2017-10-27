#include <stdio.h>
#include <math.h>

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        long long A = (long long)n * (n + 1) / 2;
        long long B = pow(2, floor(log2(n)) + 1) - 1;
        printf("%I64d\n", A - B - B);
    }
    return 0;
}
