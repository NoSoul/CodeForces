#include <stdio.h>

int Fun(int w, int h)
{
    if(w == 1) {
        return h;
    } else if(h == 1) {
        return w;
    }
    return (w + h) * 2 - 4;
}

int main()
{
    int w, h, k, ans = 0;
    scanf("%d %d %d", &w, &h, &k);
    for(int i = 0; i < k; ++i) {
        ans += Fun(w, h);
        w -= 4;
        h -= 4;
    }
    printf("%d\n", ans);
    return 0;
}
