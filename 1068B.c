#include <stdio.h>

#define MAXN    100001

char NotPrime[MAXN];
int Prime[MAXN];
int PrimeCnt;

void Sieve()
{
    int i, j;
    for(i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            Prime[PrimeCnt++] = i;
            for(j = i + i; j < MAXN; j += i) {
                NotPrime[j] = 1;
            }
        }
    }
}

int main()
{
    Sieve();
    long long b;
    scanf("%I64d", &b);
    int cnt = 1;
    long long m = b;
    for(int i = 0; i < PrimeCnt && Prime[i] <= m; ++i) {
        int cur = 0;
        while(m % Prime[i] == 0) {
            m /= Prime[i];
            ++cur;
        }
        cnt *= cur + 1;
    }
    if(m > Prime[PrimeCnt - 1]) {
        cnt *= 2;
    }
    printf("%d\n", cnt);
    return 0;
}
