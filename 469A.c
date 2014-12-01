#include <stdio.h>

char Hash[101];

int main()
{
    int N, M, i, Num, Ans = 0;
    scanf("%d", &N);
    for(i = 0; i < 2; ++i)
    {
        scanf("%d", &M);
        while(M--)
        {
            scanf("%d", &Num);
            if(!Hash[Num])
            {
                Hash[Num] = 1;
                ++Ans;
            }
        }
    }
    puts(Ans == N ? "I become the guy." : "Oh, my keyboard!");
    return 0;
}
