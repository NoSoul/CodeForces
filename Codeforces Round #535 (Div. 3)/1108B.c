#include <stdio.h>

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    int d[128];
    scanf("%d", &n);
    int x, y;
    x = y = 1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &d[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(d[i] > d[j]) {
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    x = d[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        if(x % d[i]) {
            y = d[i];
            break;
        }
    }
    if(y == 1) {
        for(int i = 1; i < n; ++i) {
            if(d[i] == d[i - 1]) {
                y = d[i];
            }
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}
