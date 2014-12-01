#include <stdio.h>

int main()
{
    int N, i, a, b, flag;
    scanf("%d", &N);
    flag = 0;
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &a, &b);
        if(a != b)
        {
            flag = 1;
        }
    }
    if(N == 1)
    {
        puts("Poor Alex");
        return 0;
    }
    puts(flag ? "Happy Alex" : "Poor Alex");
    return 0;
}
