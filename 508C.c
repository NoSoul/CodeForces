#include <stdio.h>

char Flag[601];
int Cnt[601];

int main()
{
    int m, t, r, w, i, j;
    scanf("%d %d %d", &m, &t, &r);
    while(m--)
    {
        scanf("%d", &w);
        w += 300;
        Flag[w] = 1;
    }
    int Cur = 0;
    for(i = 0; i < 601; ++i)
    {
        Cur += Cnt[i];
        if(Flag[i] == 1)
        {
            if(Cur < r)
            {
                int target = r - Cur;
                for(j = i - 1; j >= i - t && j >= 0; --j)
                {
                    if(Flag[j] == 0)
                    {
                        Flag[j] = 2;
                        ++Cnt[j + 1];
                        if(j + t + 1 < 601)
                        {
                            --Cnt[j + t + 1];
                        }
                        if(--target == 0)
                        {
                            break;
                        }
                    }
                }
                if(target == 0)
                {
                    Cur = r;
                }
                else
                {
                    puts("-1");
                    return 0;
                }
            }
            Flag[i] = 0;
        }
    }
    Cur = 0;
    for(i = 0; i < 601; ++i)
    {
        Cur += Flag[i] == 2;
    }
    printf("%d\n", Cur);
    return 0;
}
