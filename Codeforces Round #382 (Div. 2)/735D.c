#include <stdio.h>

#define MAXN    44730

char NotPrime[MAXN];
int Prime[MAXN];
int PrimeCnt;

void Sieve()
{
    for(int i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            for(int j = i + i; j < MAXN; j += i) {
                NotPrime[j] = 1;
            }
        }
    }
    for(int i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            Prime[PrimeCnt++] = i;
        }
    }
}

int IsPrime(int n)
{
    if(n < 2) {
        return 0;
    }
    for(int i = 0; i < PrimeCnt && Prime[i] < n; ++i) {
        if(n % Prime[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    Sieve();
    scanf("%d", &n);
    if(IsPrime(n)) {
        printf("%d\n", 1);
    } else {
        char haveTow = 0;
        for(int i = 0; i < PrimeCnt; ++i) {
            if(IsPrime(n - Prime[i])) {
                haveTow = 1;
                break;
            }
        }
        printf("%d\n", haveTow ? 2 : 3);
    }
    return 0;
}
