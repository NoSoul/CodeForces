#include <stdio.h>
#include <string.h>

int main()
{
    char Str[3][51];
    memset(Str[0], '#', sizeof(Str[0]));
    memset(Str[1], '.', sizeof(Str[1]));
    memset(Str[2], '.', sizeof(Str[2]));
    Str[2][0] = '#';
    int N, M, i;
    scanf("%d %d", &N, &M);
    Str[0][M] = '\0';
    Str[1][M] = '\0';
    Str[2][M] = '\0';
    Str[1][M - 1] = '#';
    for(i = 0; i < N; ++i)
    {
        puts((i & 1) ? ((i & 3) == 1 ? Str[1] : Str[2]) : Str[0]);
    }
    return 0;
}
