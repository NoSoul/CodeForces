#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Val[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void Func(int n, int *data)
{
    memset(data, 0, 10 * sizeof(int));
    if(n == 0) {
        data[0] = 1;
        return;
    }
    int m, len = 0, i, j, mod = 1, nprime;
    m = n;
    while(m) {
        m /= 10;
        ++len;
    }
    nprime = n;
    for(i = 0; i < len; ++i) {
        if(i == 0) {
            ++data[0];
        }
        if(i != len - 1) {
            for(j = 1; j < 10; ++j) {
                data[j] += mod;
            }
            for(j = 0; j < 10; ++j) {
                data[j] += (nprime / 10 - 1) * mod;
            }
        }
        m = nprime % 10;
        for(j = i == len - 1 ? 1 : 0; j < m; ++j) {
            data[j] += mod;
        }
        data[m] += (n % mod + 1);
        mod *= 10;
        nprime /= 10;
    }
}

int main()
{
    int i, a, b, Ans = 0;
    int A[10], B[10];
    scanf("%d %d", &a, &b);
    Func(a - 1, A);
    Func(b, B);
    for(i = 0; i < 10; ++i) {
        B[i] -= A[i];
        Ans += B[i] * Val[i];
    }
    printf("%d\n", Ans);
    return 0;
}
