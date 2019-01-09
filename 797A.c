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
    int n, k;
    int ans[21];
    int size = 0;
    scanf("%d %d", &n, &k);
    if(k == 1) {
        printf("%d\n", n);
    } else {
        for(int i = 0; i < PrimeCnt && n > Prime[i]; ++i) {
            if(n % Prime[i] == 0) {
                ans[size++] = Prime[i];
                n /= Prime[i];
                if(size == k - 1 && n != 1) {
                    for(int j = 0; j < size; ++j) {
                        printf("%d ", ans[j]);
                    }
                    printf("%d\n", n);
                    return 0;
                }
                --i;
            }
        }
        puts("-1");
    }
    return 0;
}
