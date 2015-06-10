#include <stdio.h>

char Custom[1001];
char NotPrime[1001];
int PrimeList[1001];
int PrimeLen;

void MakePrime()
{
    int i, j;
    for(i = 2; i < 1001; ++i) {
        if(!NotPrime[i]) {
            for(j = i + i; j < 1001; j += i) {
                NotPrime[j] = 1;
            }
            PrimeList[PrimeLen++] = i;
        }
    }
}

int main()
{
    int N, K, i, Cnt = 0;
    scanf("%d %d", &N, &K);
    MakePrime();
    for(i = 0; i < PrimeLen - 1; ++i) {
        int num = 1 + PrimeList[i] + PrimeList[i + 1];
        if(num < 1001) {
            if(!NotPrime[num]) {
                Custom[num] = 1;
            }
        }
    }
    for(i = 2; i <= N; ++i) {
        Cnt += Custom[i];
    }
    puts(Cnt >= K ? "YES" : "NO");
    return 0;
}
