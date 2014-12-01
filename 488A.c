#include <stdio.h>

int Luck(int N)
{
    int a;
    if(N < 0)
    {
        N = -N;
    }
    while(N)
    {
        a = N % 10;
        if(a == 8)
        {
            return 1;
        }
        N /= 10;
    }
    return 0;
}

int main()
{
    int N, Cnt = 0;
    scanf("%d", &N);
    while(1)
    {
        ++N;
        ++Cnt;
        if(Luck(N))
        {
            printf("%d\n", Cnt);
            break;
        }
    }
    return 0;
}
