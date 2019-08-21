#include <stdio.h>

int main()
{
    int n, l, r, data;
    scanf("%d %d %d", &n, &l, &r);
    int min = n - (l - 1);
    data = 2;
    for(int i = 1; i < l; ++i) {
        min += data;
        data *= 2;
    }
    int max = (1 << (r - 1)) * (n - r + 1);
    data = 1;
    for(int i = 1; i < r; ++i) {
        max += data;
        data *= 2;
    }
    printf("%d %d", min, max);
    return 0;
}
