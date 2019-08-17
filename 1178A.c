#include <stdio.h>

int main()
{
    int a[100];
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int coalition = a[0];
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(a[0] >= a[i] * 2) {
            coalition += a[i];
            ++cnt;
        }
    }
    if(coalition * 2 > sum) {
        printf("%d\n1 ", cnt);
        for(int i = 1; i < n; ++i) {
            if(a[0] >= a[i] * 2) {
                printf("%d ", i + 1);
            }
        }
    } else {
        puts("0");
    }
    return 0;
}
