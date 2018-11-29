#include <stdio.h>

int main()
{
    int n, cnt = 0;
    int a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n - 1; ++i) {
        if(a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            ++cnt;
            a[i + 1] = 0;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
