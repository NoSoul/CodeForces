#include <stdio.h>

int main()
{
    int n;
    int a[200];
    scanf("%d", &n);
    n *= 2;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        int k = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[k] < a[j]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    puts(a[n / 2 - 1] > a[n / 2] ? "YES" : "NO");
    return 0;
}
