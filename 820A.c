#include <stdio.h>

int main()
{
    int c, v0, v1, a, l;
    int cnt, Ans;
    scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
    Ans = 1;
    cnt = v0;
    while(1) {
        if(cnt >= c) {
            break;
        }
        int want = v0 + a * Ans;
        int real = want;
        if(want > v1) {
            real = v1;
        }
        cnt += real - l;
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
