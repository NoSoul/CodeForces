#include <stdio.h>

int main()
{
    int n;
    int a[1000], b[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        if(a[i] != b[i]) {
            puts("rated");
            return 0;
        }
    }
    for(int i = 0; i < n - 1; ++i) {
        if(a[i] < a[i + 1]) {
            puts("unrated");
            return 0;
        }
    }
    puts("maybe");
    return 0;
}
