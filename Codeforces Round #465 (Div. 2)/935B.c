#include <stdio.h>

int IsA(int x, int y)
{
    return y > x;
}

int IsB(int x, int y)
{
    return y < x;
}

int main()
{
    int n, x, y, ans;
    int state = 0;
    char str[100001];
    scanf("%d %s", &n, str);
    ans = x = y = 0;
    for(int i = 0; i < n; ++i) {
        int newX, newY;
        if(str[i] == 'U') {
            newX = x;
            newY = y + 1;
        } else {
            newX = x + 1;
            newY = y;
        }
        if(IsA(newX, newY)) {
            if(state == 1) {
                ++ans;
            }
            state = -1;
        }
        if(IsB(newX, newY)) {
            if(state == -1) {
                ++ans;
            }
            state = 1;
        }
        x = newX;
        y = newY;
    }
    printf("%d\n", ans);
    return 0;
}
