#include <stdio.h>

typedef __int64 LL_t;

LL_t PowExp(LL_t n, int p)
{
    LL_t k = 1;
    while(p != 1) {
        if(p & 1) {
            k *= n;
        }
        n *= n;
        p >>= 1;
    }
    return n * k;
}

int main()
{
    int i;
    LL_t p, d, m;
    scanf("%I64d %I64d", &p, &d);
    d = p - d;
    m = p;
    i = 0;
    while(m) {
        ++i;
        m /= 10;
    }
    --i;
    if(i == 0) {
        printf("%I64d\n", p);
        return 0;
    }
    if((p + 1) == (p / PowExp(10, i) + 1)*PowExp(10, i)) {
        printf("%I64d\n", p);
        return 0;
    }
    while(i) {
        if((p / PowExp(10, i))*PowExp(10, i) - 1 >= d) {
            printf("%I64d\n", (p / PowExp(10, i))*PowExp(10, i) - 1);
            return 0;
        }
        --i;
    }
    printf("%I64d\n", p);
    return 0;
}
