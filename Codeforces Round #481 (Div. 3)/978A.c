#include <stdio.h>

char flag[1001];

int main()
{
    int n;
    scanf("%d", &n);
    int a[50];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        flag[a[i]] = i + 1;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        cnt += flag[a[i]] == i + 1;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < n; ++i) {
        if(flag[a[i]] == i + 1) {
            printf("%d ", a[i]);
        }
    }
    puts("");
    return 0;
}
