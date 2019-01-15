#include <stdio.h>

int main()
{
    int n, maxIdx = 0, minIdx = 0;
    int x[1000], y[1000];
    int a[1000], b[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        if(i && (x[maxIdx] < x[i] || (x[maxIdx] == x[i] && y[maxIdx] < y[i]))) {
            maxIdx = i;
        }
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        if(i && (a[minIdx] > a[i] || (a[minIdx] == a[i] && b[minIdx] > b[i]))) {
            minIdx = i;
        }
    }
    printf("%d %d\n", x[maxIdx] + a[minIdx], y[maxIdx] + b[minIdx]);
    return 0;
}
