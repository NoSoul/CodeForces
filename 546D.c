#include <stdio.h>

#define MAXN    5000001

int PrimeList[MAXN];
int PrimeLen;
char NotPrime[MAXN];
int Ans[MAXN];

void MakePrime()
{
    int i, j;
    for(i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            for(j = i + i; j < MAXN; j += i) {
                NotPrime[j] = 1;
            }
            PrimeList[PrimeLen++] = i;
        }
    }
}

void MakeAns()
{
    int i, j;
    Ans[1] = 0;
    for(i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            Ans[i] = Ans[i - 1] + 1;
            continue;
        }
        int num = i;
        Ans[i] = Ans[i - 1];
        for(j = 0; PrimeList[j] <= num; ++j) {
            if(!NotPrime[num]) {
                ++Ans[i];
                break;
            }
            int cur = 0;
            while(num % PrimeList[j] == 0) {
                num /= PrimeList[j];
                ++cur;
            }
            Ans[i] += cur;
        }
    }
}

int main()
{
    MakePrime();
    MakeAns();
    int T, a, b;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", Ans[a] - Ans[b]);
    }
    return 0;
}
