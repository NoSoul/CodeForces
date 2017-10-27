#include <stdio.h>

#define MAXN    40000

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
    int n, i, j;
    scanf("%d", &n);
    if(n == 3 || n == 5) {
        printf("1\n%d\n", n);
        return 0;
    }
    printf("3\n3 ");
    n -= 3;
    for(i = 0; Prime[i] <= n; ++i) {
        int m = n - Prime[i];
        for(j = 0; Prime[j]*Prime[j] <= m; ++j) {
            if(m % Prime[j] == 0) {
                break;
            }
        }
        if(Prime[j]*Prime[j] > m) {
            printf("%d %d\n", Prime[i], n - Prime[i]);
            break;
        }
    }
    return 0;
}
