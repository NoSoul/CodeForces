#include <stdio.h>

int main()
{
    int d1, d2, d3, Ans;
    scanf("%d %d %d", &d1, &d2, &d3);
    Ans = d1 + d2 + d3;
    if(2 * d1 + 2 * d2 < Ans) {
        Ans = 2 * d1 + 2 * d2;
    }
    if(2 * d1 + 2 * d3 < Ans) {
        Ans = 2 * d1 + 2 * d3;
    }
    if(2 * d2 + 2 * d3 < Ans) {
        Ans = 2 * d2 + 2 * d3;
    }
    printf("%d\n", Ans);
    return 0;
}
