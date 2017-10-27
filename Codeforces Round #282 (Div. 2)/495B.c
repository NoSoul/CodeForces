#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, i, Ans;
    Ans = 0;
    scanf("%d %d", &a, &b);
    if(a == b) {
        puts("infinity");
    } else if(a < b) {
        puts("0");
    } else {
        int j = sqrt(a - b);
        for(i = 1; i <= j; ++i) {
            if((a - b) % i == 0) {
                int x = (a - b) / i;
                if(a % i == b) {
                    ++Ans;
                }
                if(a % x == b) {
                    ++Ans;
                }
                if(a % i == b && x == i) {
                    --Ans;
                }
            }
        }
        printf("%d\n", Ans);
    }
    return 0;
}
