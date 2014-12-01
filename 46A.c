#include <stdio.h>

int main()
{
    int N, i, now;
    scanf("%d", &N);
    printf("2");
    for(now = i = 2; i < N; ++i)
    {
        now += i;
        now %= N;
        if(now == 0)
        {
            now = N;
        }
        printf(" %d", now);
    }
    puts("");
    return 0;
}
