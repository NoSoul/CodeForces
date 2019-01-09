#include <stdio.h>

int GetQ(int aX, int aY, int x, int y)
{
    if(x < aX && y < aY) {
        return 0;
    }
    if(x > aX && y < aY) {
        return 1;
    }
    if(x > aX && y > aY) {
        return 2;
    }
    return 3;
}

int main()
{
    int n, aX, aY, bX, bY, cX, cY;
    scanf("%d %d %d %d %d %d %d", &n, &aX, &aY, &bX, &bY, &cX, &cY);
    puts(GetQ(aX, aY, bX, bY) == GetQ(aX, aY, cX, cY) ? "YES" : "NO");
    return 0;
}
