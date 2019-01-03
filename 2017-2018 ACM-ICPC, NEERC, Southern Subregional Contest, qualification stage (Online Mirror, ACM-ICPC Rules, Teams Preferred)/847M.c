#include <stdio.h>

int main()
{
    int n;
    int t[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    for(int i = 2; i < n; ++i) {
        if(t[i] - t[i - 1] != t[1] - t[0]) {
            printf("%d\n", t[n - 1]);
            return 0;
        }
    }
    printf("%d\n", t[n - 1] + (t[n - 1] - t[n - 2]));
    return 0;
}
