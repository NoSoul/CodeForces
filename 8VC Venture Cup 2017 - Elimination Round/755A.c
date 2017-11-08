#include <stdio.h>

#define MAXN    100001
char NotPrime[MAXN];

void SieveOfEratosthenes()
{
    NotPrime[0] = 1;
    NotPrime[1] = 1;
    for(int i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            for(int j = i + i; j < MAXN; j += i) {
                NotPrime[j] = 1;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    SieveOfEratosthenes();
    for(int i = 2; i < MAXN; ++i) {
        if(NotPrime[i]) {
            if((i - 1) % n == 0) {
                printf("%d\n", (i - 1) / n);
                return 0;
            }
        }
    }
    return 0;
}
