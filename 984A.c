#include <stdio.h>

int main()
{
    int n;
    int a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        int k = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[j] < a[k]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    printf("%d\n", a[(n - 1) / 2]);
    return 0;
}
