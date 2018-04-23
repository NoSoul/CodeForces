#include <stdio.h>

int main()
{
    int x, hh, mm, ans = 0;
    scanf("%d %d %d", &x, &hh, &mm);
    while(1) {
        if((hh % 10 == 7 || mm % 10 == 7) && ans % x == 0) {
            break;
        }
        if(--mm == -1) {
            mm = 59;
            if(--hh == -1) {
                hh = 23;
            }
        }
        ++ans;
    }
    printf("%d\n", ans / x);
    return 0;
}
