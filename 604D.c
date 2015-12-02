#include <stdio.h>

char Flag[1000000];
int A[1000000];

int ModExp(int n, int m, int p)
{
    int k = 1;
    n %= p;
    while(m != 1) {
        if(m & 1) {
            k = ((long long)k * n) % p;
        }
        n = ((long long)n * n) % p;
        m >>= 1;
    }
    return ((long long)n * k) % p;
}

int main()
{
    int p, k, i, exp = 0;
    scanf("%d %d", &p, &k);
    if(k == 0) {
        printf("%d\n", ModExp(p, p - 1, 1000000007));
        return 0;
    } else if(k == 1) {
        printf("%d\n", ModExp(p, p, 1000000007));
        return 0;
    }
    for(i = 1; i < p; ++i) {
        A[((long long)i * k) % p] = i;
    }
    for(i = 1; i < p; ++i) {
        if(!Flag[i]) {
            ++exp;
        }
        int j = i;
        while(!Flag[j]) {
            Flag[j] = 1;
            j = A[j];
        }
    }
    printf("%d\n", ModExp(p, exp, 1000000007));
    return 0;
}
