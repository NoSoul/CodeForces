#include <stdio.h>
#include <string.h>

int ExpMod(int a, int n, int mod)
{
    int ans = 1;
    a %= mod;
    while(n) {
        if(n & 1) {
            ans = ((long long)ans  * a) % mod;
        }
        a = ((long long)a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int main()
{
    int N, i, j;
    int A[4];
    char Str[100001];
    memset(A, 0, sizeof(A));
    scanf("%d %s", &N, Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'A') {
            ++A[0];
        } else if(Str[i] == 'C') {
            ++A[1];
        } else if(Str[i] == 'G') {
            ++A[2];
        } else if(Str[i] == 'T') {
            ++A[3];
        }
    }
    int idx = 0, Cnt = 1;
    for(i = 1; i < 4; ++i) {
        if(A[i] > A[idx]) {
            idx = i;
            Cnt = 1;
        } else if(A[i] == A[idx]) {
            ++Cnt;
        }
    }
    printf("%d\n", ExpMod(Cnt, N, 1000000000 + 7));
    return 0;
}
