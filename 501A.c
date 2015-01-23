#include <stdio.h>

int GetPoint(int p, int t)
{
    int a = 3 * p / 10;
    int b = p - t * p / 250;
    return a > b ? a : b;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int A = GetPoint(a, c);
    int B = GetPoint(b, d);
    if(A > B)
    {
        puts("Misha");
    }
    else if(A < B)
    {
        puts("Vasya");
    }
    else
    {
        puts("Tie");
    }
    return 0;
}
