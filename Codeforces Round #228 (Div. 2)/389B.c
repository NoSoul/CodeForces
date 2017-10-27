#include <stdio.h>

int main()
{
    int N, i, j;
    char Str[101][101];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%s", &Str[i]);
    }
    for(i = 0; i < N; ++i) {
        for(j = 0; j < N; ++j) {
            if(Str[i][j] == '#') {
                if((i + 2) >= N || (j - 1) < 0 || (j + 1) >= N) {
                    puts("NO");
                    return 0;
                }
                if(Str[i + 1][j] != '#' || Str[i + 1][j - 1] != '#' || Str[i + 1][j + 1] != '#' || Str[i + 2][j] != '#') {
                    puts("NO");
                    return 0;
                }
                Str[i][j] = '.';
                Str[i + 1][j] = '.';
                Str[i + 1][j - 1] = '.';
                Str[i + 1][j + 1] = '.';
                Str[i + 2][j] = '.';
            }
        }
    }
    puts("YES");
    return 0;
}
