#include <stdio.h>

int main()
{
    int T, n, s, t;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &n, &s, &t);
        int overLap = s + t - n;
        s -= overLap;
        t -= overLap;
        printf("%d\n", (s > t ? s : t) + 1);
    }
    return 0;
}
