#include <stdio.h>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    int bound = 0;
    for(int i = 1; i < 61; ++i) {
        if((1LL << i) > n) {
            bound = i;
            break;
        }
    }
    if(k == 1) {
        printf("%I64d\n", n);
    } else {
        printf("%I64d\n", (1LL << bound) - 1);
    }
    return 0;
}
