#include <stdio.h>

int main()
{
    int n;
    int a[200001];
    int b[200001];
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int idx = 1;
    char back = 1;
    while(1) {
        if(back) {
            b[idx] = a[n - idx + 1];
            b[n - idx + 1] = a[idx];
        } else {
            b[idx] = a[idx];
            b[n - idx + 1] = a[n - idx + 1];
        }
        ++idx;
        back ^= 1;
        if(idx > n - idx + 1) {
            break;
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}
