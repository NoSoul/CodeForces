#include <stdio.h>

#define MAXN    447220

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
    int t;
    scanf("%d", &t);
    while(t--) {
        long long a, b;
        scanf("%I64d %I64d", &a, &b);
        if(a - b > 1) {
            puts("NO");
        } else {
            a += b;
            char find = 0;
            for(int i = 0; i < PrimeCnt && a > Prime[i]; ++i) {
                if(a % Prime[i] == 0) {
                    find = 1;
                    break;
                }
            }
            puts(!find ? "YES" : "NO");
        }
    }
    return 0;
}
