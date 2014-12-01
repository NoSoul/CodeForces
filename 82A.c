#include <stdio.h>

int main()
{
    int N, a, i, j;
    char SName[5][10] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    while(scanf("%d", &N) != EOF)
    {
        for(a = 1, i = 0; i < 30; ++i)
        {
            if(N > 5 * a)
            {
                N -= 5 * a;
            }
            else
            {
                for(j = 0; j < 5; ++j)
                {
                    if(N > a)
                    {
                        N -= a;
                    }
                    else
                    {
                        puts(SName[j]);
                        break;
                    }
                }
                break;
            }
            a *= 2;
        }
    }
    return 0;
}
