#include <stdio.h>

#define MAXN    31630

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
    int n, ans;
    scanf("%d", &n);
    Sieve();
    ans = n;
    while(n != 1) {
        int i;
        for(i = 0; i < PrimeCnt; ++i) {
            if(n % Prime[i] == 0) {
                break;
            }
        }
        if(i == PrimeCnt) {
            ans += n / n;
            n /= n;
        } else {
            ans += n / Prime[i];
            n /= Prime[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
