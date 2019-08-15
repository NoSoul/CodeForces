#include <stdio.h>

int main()
{
    int a[3], d;
    for(int i = 0; i < 3; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &d);
    for(int i = 0; i < 3; ++i) {
        for(int j = i + 1; j < 3; ++j) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < 3; ++i) {
        int delta = a[i] - a[i - 1];
        if(delta < d) {
            ans += d - delta;
        }
    }
    printf("%d\n", ans);
    return 0;
}
