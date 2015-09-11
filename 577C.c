#include <stdio.h>

#define MAXN    1001

char NotPrime[MAXN];
int Prime[MAXN];
int PrimeCnt;
int PrimeExp[MAXN];
int Ans[MAXN];
int Size;

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
    int N, i, j;
    Sieve();
    scanf("%d", &N);
    for(i = 2; i <= N; ++i) {
        int num = i;
        char flag = 0;
        for(j = 0; j < PrimeCnt && Prime[j] <= num; ++j) {
            int exp = 0;
            while(num % Prime[j] == 0) {
                ++exp;
                num /= Prime[j];
            }
            if(exp > PrimeExp[j]) {
                PrimeExp[j] = exp;
                flag = 1;
            }
        }
        if(flag) {
            Ans[Size++] = i;
        }
    }
    printf("%d\n", Size);
    for(i = 0; i < Size; ++i) {
        printf("%d ", Ans[i]);
    }
    puts("");
    return 0;
}
