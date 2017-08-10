#include <stdio.h>

int main()
{
    int a, b, ans = 0;
    scanf("%02d:%02d", &a, &b);
    while(1) {
        if(a / 10 == b % 10 && a % 10 == b / 10) {
            break;
        }
        ++ans;
        if(++b == 60) {
            b = 0;
            if(++a == 24) {
                a = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
