#include <stdio.h>

int main()
{
    int n;
    int a[2000];
    scanf("%d", &n);
    for(int i = 0; i < 2 * n; ++i) {
        scanf("%d", &a[i]);
    }
    int sumA = 0;
    int sumB = 0;
    for(int i = 0; i < n; ++i) {
        sumA += a[i];
    }
    for(int i = n; i < 2 * n; ++i) {
        sumB += a[i];
    }
    if(sumA == sumB) {
        for(int i = 0; i < n; ++i) {
            for(int j = n; j < 2 * n; ++j) {
                if(a[i] != a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    for(int k = 0; k < 2 * n; ++k) {
                        printf("%d ", a[k]);
                    }
                    return 0;
                }
            }
        }
        puts("-1");
    } else {
        for(int i = 0; i < 2 * n; ++i) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}
