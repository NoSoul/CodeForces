#include <stdio.h>

int main()
{
    int y, b, r;
    scanf("%d %d %d", &y, &b, &r);
    b -= 1;
    r -= 2;
    int ans = y;
    if(ans > b) {
        ans = b;
    }
    if(ans > r) {
        ans = r;
    }
    ++ans;
    printf("%d\n", 3 * ans);
    return 0;
}
