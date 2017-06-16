#include <stdio.h>

#define MAXN 100002

char NotPrime[MAXN];

void SieveOfEratosthenes()
{
    int i, j;
    NotPrime[0] = 1;
    NotPrime[1] = 1;
    for(i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            for(j = i + i; j < MAXN; j += i) {
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
    int a = 0, b = 0;
    for(int i = 2; i <= n + 1; ++i) {
        if(NotPrime[i]) {
            a = 1;
        } else {
            b = 1;
        }
    }
    printf("%d\n", a + b);
    for(int i = 2; i <= n + 1; ++i) {
        printf("%d ", NotPrime[i] ? 2 : 1);
    }
    puts("");
    return 0;
}
