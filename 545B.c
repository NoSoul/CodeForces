#include <stdio.h>

int main()
{
    char S[100001];
    char T[100001];
    int i, N = 0;
    scanf("%s %s", S, T);
    for(i = 0; S[i] != '\0'; ++i)
    {
        if(S[i] != T[i])
        {
            ++N;
        }
    }
    if(N & 1)
    {
        puts("impossible");
        return 0;
    }
    N /= 2;
    for(i = 0; S[i] != '\0'; ++i)
    {
        if(S[i] != T[i])
        {
            putchar(N ? S[i] : T[i]);
            if(N)
            {
                --N;
            }
        }
        else
        {
            putchar(S[i]);
        }
    }
    putchar('\n');
    return 0;
}
