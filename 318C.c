#include <stdio.h>

typedef long long LL_t;

int main()
{
    LL_t x, y, m, temp, Cnt;
    while(scanf("%I64d %I64d %I64d", &x, &y, &m) != EOF)
    {
        if(x < y)
        {
            temp = x;
            x = y;
            y = temp;
        }
        if(x >= m)
        {
            printf("0\n");
            continue;
        }
        if(x <= 0)
        {
            printf("-1\n");
            continue;
        }
        if(y < 0)
        {
            y = -y;
            if(y % x != 0)
            {
                Cnt = y / x + 1;
                y = x - y % x;
            }
            else
            {
                Cnt = y / x;
                y = 0;
            }
        }
        else
        {
            Cnt = 0;
        }
        while(1)
        {
            ++Cnt;
            temp = x + y;
            y = temp;
            if(temp >= m)
            {
                printf("%I64d\n", Cnt);
                break;
            }
            temp = x;
            x = y;
            y = temp;
        }
    }
    return 0;
}
