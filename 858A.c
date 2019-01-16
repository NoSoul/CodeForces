#include <stdio.h>

int GCD(int a, int b)
{
    int temp;
    while(b) {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int m = 1;
    for(int i = 0; i < k; ++i) {
        m *= 10;
    }
    printf("%I64d\n", (long long)n * m / GCD(m, n));
    return 0;
}
