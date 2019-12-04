#include <stdio.h>

int main()
{
    int n;
    int a[100];
    char visit[101] = {0};
    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(!visit[a[i]]) {
            ++ans;
            for(int j = a[i]; j < 101; j += a[i]) {
                visit[j] = 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
