#include <stdio.h>

char Str[100][101];

int Fun(int i, int j, int N)
{
    int Sum = 0;
    if(i-1 >= 0)
    {
        if(Str[i-1][j] == 'o')
        {
            ++Sum;
        }
    }
    if(i+1 < N)
    {
        if(Str[i+1][j] == 'o')
        {
            ++Sum;
        }
    }
    if(j-1 >= 0)
    {
        if(Str[i][j-1] == 'o')
        {
            ++Sum;
        }
    }
    if(j+1 < N)
    {
        if(Str[i][j+1] == 'o')
        {
            ++Sum;
        }
    }
    return Sum&1;
}

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%s", Str[i]);
    }
    for(i=0; i<N; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(Fun(i, j, N))
            {
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    return 0;
}
