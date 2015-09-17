#include <stdio.h>

int main()
{
    int x, Ans = 0;
    scanf("%d", &x);
    while(x) {
        if(x & 1) {
            ++Ans;
        }
        x >>= 1;
    }
    printf("%d\n", Ans);
    return 0;
}
