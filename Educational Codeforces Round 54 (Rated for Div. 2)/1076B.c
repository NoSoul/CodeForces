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
    long long N, ans = 0;
    Sieve();
    scanf("%I64d", &N);
    while(N) {
        if((N & 1) == 0) {
            ans += N / 2;
            break;
        }
        int i;
        for(i = 1; i < PrimeCnt; ++i) {
            if(N % Prime[i] == 0) {
                N -= Prime[i];
                ++ans;
                break;
            }
        }
        if(i == PrimeCnt) {
            N = 0;
            ++ans;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
