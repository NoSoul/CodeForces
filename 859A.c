#include <stdio.h>

int main()
{
    int a[25];
    int K, r, size = 0;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i) {
        scanf("%d", &r);
        if(r > 25) {
            a[size++] = r;
        }
    }
    for(int i = 0; i < size; ++i) {
        for(int j = i + 1; j < size; ++j) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int ans = size;
    for(int i = 0; i < size; ++i) {
        if(i == 0) {
            ans += a[i] - 25 - 1;
        } else {
            ans += a[i] - a[i - 1] - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
