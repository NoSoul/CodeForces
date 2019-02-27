#include <stdio.h>

int main()
{
    int n, a, b;
    int h[2000];
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(h[i] < h[j]) {
                int temp = h[i];
                h[i] = h[j];
                h[j] = temp;
            }
        }
    }
    printf("%d\n", h[a - 1] == h[a] ? 0 : h[a - 1] - h[a]);
    return 0;
}
