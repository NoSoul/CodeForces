#include <stdio.h>

int main()
{
    int a1, a2, Ans = 0;
    scanf("%d %d", &a1, &a2);
    while(1) {
        if(a1 <= 0 || a2 <= 0) {
            break;
        }
        if(a1 < a2) {
            a1 += 1;
            if(a1 > 100) {
                a1 = 100;
            }
            a2 -= 2;

        } else {
            a2 += 1;
            if(a2 > 100) {
                a2 = 100;
            }
            a1 -= 2;
        }
        if(a1 < 0 || a2 < 0) {
            break;
        }
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
