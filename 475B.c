#include <stdio.h>

int main()
{
    int N, M, i;
    char Str[2][21];
    scanf("%d %d", &N, &M);
    for(i=0; i<2; ++i)
    {
        scanf("%s", Str[i]);
    }
    puts((Str[0][0]=='<'&&Str[1][0]=='^')
         ||(Str[0][0]=='>'&&Str[1][M-1]=='^')
         ||(Str[0][N-1]=='<'&&Str[1][0]=='v')
         ||(Str[0][N-1]=='>'&&Str[1][M-1]=='v')?"NO":"YES");
    return 0;
}
