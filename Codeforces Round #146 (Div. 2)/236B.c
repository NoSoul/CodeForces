#include <stdio.h>

#define MAXN 1001
#define MOD (1<<30)

int Prime[170];
char B[MAXN];
int Cnt;

void Make()
{
    int i, j;
    for(Cnt = 0, i = 2; i < MAXN; ++i) {
        if(!B[i]) {
            Prime[Cnt++] = i;
            for(j = i << 1; j < MAXN; j += i) {
                B[j] = 1;
            }
        }
    }
    return;
}

int F(int N)
{
    int i, j, r = 1;
    for(i = 0; i < Cnt && Prime[i] <= N; ++i) {
        if(N % Prime[i] == 0) {
            j = 1;
            while(N % Prime[i] == 0) {
                N /= Prime[i];
                ++j;
            }
            r *= j;
        }
    }
    return r;
}

int main()
{
    int a, b, c, i, j, k, Sum = 0;
    Make();
    scanf("%d %d %d", &a, &b, &c);
    for(i = 1; i <= a; ++i) {
        for(j = 1; j <= b; ++j) {
            for(k = 1; k <= c; ++k) {
                Sum = (Sum % MOD + F(i * j * k) % MOD) % MOD;
            }
        }
    }
    printf("%d\n", Sum);
    return 0;
}
