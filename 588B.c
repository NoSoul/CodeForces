#include <stdio.h>

#define MAXN    1000001

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
    int i;
    long long Num, Ans = 1;
    scanf("%I64d", &Num);
    for(i = 0; Prime[i] <= Num && i < PrimeCnt; ++i) {
        char flag = 0;
        while(Num % Prime[i] == 0) {
            flag = 1;
            Num /= Prime[i];
        }
        if(flag) {
            Ans *= Prime[i];
        }
    }
    printf("%I64d\n", Ans * Num);
    return 0;
}
