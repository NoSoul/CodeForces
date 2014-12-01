#include <stdio.h>

int main()
{
    int N, x, y, A, B, X, Y;
    scanf("%d", &N);
    X = Y = A = B = 0;
    while(N--)
    {
        scanf("%d %d", &x, &y);
        if((x & 1) == 0 && (y & 1) == 1)
        {
            ++A;
        }
        if((x & 1) == 1 && (y & 1) == 0)
        {
            ++B;
        }
        X += x;
        Y += y;
    }
    if((X & 1) == 0 && (Y & 1) == 0)
    {
        puts("0");
        return 0;
    }
    if(((X + Y) & 1) == 1)
    {
        puts("-1");
        return 0;
    }
    puts(A + B > 0 ? "1" : "-1");
    return 0;
}
