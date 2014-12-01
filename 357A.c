#include <stdio.h>

int Hash[101];

int main()
{
    int m, i, x, y;
    scanf("%d", &m);
    for(i = 0; i < m; ++i)
    {
        scanf("%d", &Hash[i + 1]);
    }
    for(i = 99; i >= 0; --i)
    {
        Hash[i] += Hash[i + 1];
    }
    scanf("%d %d", &x, &y);
    for(i = 1; i < 101; ++i)
    {
        if(Hash[i] >= x && Hash[i] <= y && (Hash[0] - Hash[i]) >= x && (Hash[0] - Hash[i]) <= y)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("0");
    return 0;
}
