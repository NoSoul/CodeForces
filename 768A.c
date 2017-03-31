#include <stdio.h>

int main()
{
    int n, min = 0x7fffffff, max = 0, cnt = 0;
    int a[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(min > a[i]) {
            min = a[i];
        }
        if(max < a[i]) {
            max = a[i];
        }
    }
    for(int i = 0; i < n; ++i) {
        if(a[i] != min && a[i] != max) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
