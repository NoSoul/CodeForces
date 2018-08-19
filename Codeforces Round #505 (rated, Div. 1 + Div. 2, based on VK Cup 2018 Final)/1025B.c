#include <stdio.h>

#define MAXN    44730

char NotPrime[MAXN];
int Prime[MAXN];
int PrimeCnt;

void Sieve()
{
    for(int i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            for(int j = i + i; j < MAXN; j += i) {
                NotPrime[j] = 1;
            }
        }
    }
    for(int i = 2; i < MAXN; ++i) {
        if(!NotPrime[i]) {
            Prime[PrimeCnt++] = i;
        }
    }
}

int A[150001];
int B[150001];

int main()
{
    int n;
    scanf("%d", &n);
    Sieve();
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &A[i], &B[i]);
    }
    int factor[MAXN];
    int size = 0;
    for(int i = 0; i < PrimeCnt; ++i) {
        if(A[0] % Prime[i] == 0 || B[0] % Prime[i] == 0) {
            factor[size++] = Prime[i];
        }
        while(A[0] % Prime[i] == 0) {
            A[0] /= Prime[i];
        }
        while(B[0] % Prime[i] == 0) {
            B[0] /= Prime[i];
        }
    }
    if(A[0] != 1) {
        factor[size++] = A[0];
    }
    if(B[0] != 1) {
        factor[size++] = B[0];
    }
    for(int j = 0; j < size; ++j) {
        char find = 1;
        for(int i = 1; i < n; ++i) {
            if(!(A[i] % factor[j] == 0 || B[i] % factor[j] == 0)) {
                find = 0;
                break;
            }
        }
        if(find) {
            printf("%d\n", factor[j]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
