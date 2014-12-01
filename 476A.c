#include <stdio.h>

int main()
{
    int N, M, Two, One, Mod;
    scanf("%d %d", &N, &M);
    if(N < M)
    {
        puts("-1");
        return 0;
    }
    Two = N / 2;
    One = N & 1;
    Mod = (Two + One) % M;
    if(Mod)
    {
        Mod = M - Mod;
    }
    printf("%d\n", (Two - Mod) + One + Mod * 2);
    return 0;
}
