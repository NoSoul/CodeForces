#include <stdio.h>

int main()
{
    int N, t, num, A, B, a, b;
    scanf("%d", &N);
    a = b = A = B = 0;
    while(N--)
    {
        scanf("%d %d %*d", &t, &num);
        if(t == 1)
        {
            a += num;
            A += 10;
        }
        else
        {
            b += num;
            B += 10;
        }
    }
    if(a + a >= A)
    {
        puts("LIVE");
    }
    else
    {
        puts("DEAD");
    }
    if(b + b >= B)
    {
        puts("LIVE");
    }
    else
    {
        puts("DEAD");
    }
    return 0;
}
