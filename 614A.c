#include <stdio.h>

int main()
{
    int i, flag = 0;
    long long l, r, k, p;
    scanf("%I64d %I64d %I64d", &l, &r, &k);
    p = k;
    if(1 == l) {
        flag = 1;
        printf("1 ");
    }
    for(i = 1; i < 64; ++i) {
        if(k >= l && k <= r) {
            flag = 1;
            printf("%I64d ", k);
        }
        if(k > r / p) {
            break;
        }
        k *= p;
    }
    if(!flag) {
        printf("-1");
    }
    puts("");
    return 0;
}
