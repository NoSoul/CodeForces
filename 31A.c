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
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < n; ++k) {
                if(a[i] == a[j] + a[k] && i != j && i != k && j != k) {
                    printf("%d %d %d\n", i + 1, j + 1, k + 1);
                    return 0;
                }
            }
        }
    }
    puts("-1");
    return 0;
}
