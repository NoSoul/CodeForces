#include <stdio.h>

int main()
{
    int n, k;
    int a[100];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    int bound = n - 1;
    for(int i = 0; i < n; ++i) {
        if(a[i] <= k) {
            ++cnt;
        } else {
            bound = i;
            break;
        }
    }
    for(int i = n - 1; i > bound; --i) {
        if(a[i] <= k) {
            ++cnt;
        } else {
            break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
