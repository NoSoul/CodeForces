#include <stdio.h>
#include <stdlib.h>

int Dist(int a, int b)
{
    return abs(a - b);
}

int main()
{
    int a, b, i;
    int x, y, z;
    x = y = z = 0;
    scanf("%d %d", &a, &b);
    for(i = 1; i < 7; ++i)
    {
        if(Dist(a, i) < Dist(b, i))
        {
            ++x;
        }
        else if(Dist(a, i) == Dist(b, i))
        {
            ++y;
        }
        else
        {
            ++z;
        }
    }
    printf("%d %d %d\n", x, y, z);
    return 0;
}
