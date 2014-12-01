#include <stdio.h>

int GCD(int m, int n)
{
    int temp;
    while(n)
    {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}

int main()
{
    int a, b, c, d, p1, q1, p2, q2;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    p1 = q1 = p2 = q2 = -1;
    int g = GCD(a * d, b * c);
    if(b * c >= a * d)
    {
        p1 = a * d / g;
        q1 = b * c / g;
    }
    else
    {
        p2 = b * c / g;
        q2 = a * d / g;
    }
    if(p1 != -1)
    {
        printf("%d/%d\n", q1 - p1, q1);
    }
    else
    {
        printf("%d/%d\n", q2 - p2, q2);
    }
    return 0;
}
