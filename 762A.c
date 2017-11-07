#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    int k, m, cnt = 0, bound;
    scanf("%I64d %d", &n, &k);
    m = sqrt(n);
    for(int i = 1; i <= m; ++i) {
        if(n % i == 0) {
            ++cnt;
        }
    }
    if((long long)m * m == n) {
        bound = 2 * cnt;
    } else {
        bound = 2 * cnt + 1;
    }
    int j = 0;
    for(int i = 1; i <= m; ++i) {
        if(n % i == 0) {
            ++j;
            if(k == j) {
                printf("%d\n", i);
                return 0;
            } else if(k == bound - j) {
                printf("%I64d\n", n / i);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
