#include <stdio.h>

int main()
{
    int n, P1, P2, P3, T1, T2, ans = 0;
    scanf("%d %d %d %d %d %d", &n, &P1, &P2, &P3, &T1, &T2);
    int l, r, preR = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &l, &r);
        if(i) {
            int time = l - preR;
            if(time < T1) {
                ans += time * P1;
            } else if(time < T1 + T2) {
                ans += T1 * P1;
                ans += (time - T1) * P2;
            } else {
                ans += T1 * P1;
                ans += T2 * P2;
                ans += (time - T1 - T2) * P3;
            }
        }
        ans += (r - l) * P1;
        preR = r;
    }
    printf("%d\n", ans);
    return 0;
}
