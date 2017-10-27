#include <stdio.h>

int main()
{
    int i, j, Ans = 0;
    unsigned long long a, b;
    scanf("%I64d %I64d", &a, &b);
    unsigned long long c = 1, d;
    for(i = 1; i < 64; ++i) {
        c <<= 1;
        c |= 1;
        for(j = 0; j < i; ++j) {
            d = c ^ (1ULL << j);
            if(d >= a && d <= b) {
                ++Ans;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
