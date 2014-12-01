#include <stdio.h>

int main()
{
    int N, S, Max = -1, x, y, num, i;
    scanf("%d %d", &N, &S);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &x, &y);
        if(x * 100 + y <= S * 100)
        {
            num = 100 - y;
            if(num == 100)
            {
                num = 0;
            }
            if(num > Max)
            {
                Max = num;
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
