#include <stdio.h>

int Distance(int a, int b)
{
    if(a > b) {
        return a - b;
    }
    return b - a;
}

int main()
{
    int n, candiate;
    int c[300000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    int max = 0;
    candiate = n - 1;
    for(int i = n - 2; i >= 0; --i) {
        if(c[i] != c[n - 1]) {
            candiate = i;
        }
    }
    for(int i = 0; i <= candiate; ++i) {
        if(c[i] == c[n - 1]) {
            if(max < Distance(i, candiate)) {
                max = Distance(i, candiate);
            }
        } else {
            if(max < Distance(i, n - 1)) {
                max = Distance(i, n - 1);
            }
        }
    }
    candiate = 0;
    for(int i = 1; i < n; ++i) {
        if(c[i] != c[0]) {
            candiate = i;
        }
    }
    for(int i = candiate; i < n; ++i) {
        if(c[i] == c[0]) {
            if(max < Distance(i, candiate)) {
                max = Distance(i, candiate);
            }
        } else {
            if(max < Distance(i, 0)) {
                max = Distance(i, 0);
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
