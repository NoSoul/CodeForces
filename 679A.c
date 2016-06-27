#include <stdio.h>

#define MAXN    51

char NotPrime[MAXN];
char Prime[15];

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
    int cnt = 0;
    char ans[4];
    SieveOfEratosthenes();
    for(int i = 0; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            Prime[cnt++] = i;
        }
    }
    cnt = 0;
    for(int i = 0; i < 15; ++i) {
        printf("%d\n", Prime[i]);
        ++cnt;
        fflush(stdout);
        scanf("%s", ans);
        if(ans[0] == 'y') {
            for(int j = i; j < 15; ++j) {
                if(Prime[i]*Prime[j] < 100) {
                    printf("%d\n", Prime[i]*Prime[j]);
                    ++cnt;
                    fflush(stdout);
                    scanf("%s", ans);
                    if(ans[0] == 'y') {
                        puts("composite");
                        return 0;
                    }
                }
            }
            puts("prime");
            break;
        }
    }
    puts("prime");
    return 0;
}
