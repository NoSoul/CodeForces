#include <stdio.h>

int F(int n)
{
    int ret = 1;
    while(n) {
        if(n % 10) {
            ret *= n % 10;
        }
        n /= 10;
    }
    return ret;
}

int G(int n)
{
    if(n < 10) {
        return n;
    }
    return G(F(n));
}

int Cnt[1000001][10];

int main()
{
    for(int i = 1; i < 1000001; ++i) {
        int g = G(i);
        ++Cnt[i][g];
        for(int j = 0; j < 10; ++j) {
            Cnt[i][j] += Cnt[i - 1][j];
        }
    }
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", Cnt[r][k] - Cnt[l - 1][k]);
    }
    return 0;
}
