#include <stdio.h>

int main()
{
    int n;
    int a[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        int k = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[j] > a[k]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
    for(int i = n - (n & 1); i >= 0; i -= 2) {
        if(i <= n - 1) {
            printf("%d ", a[i]);
        }
    }
    for(int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}
