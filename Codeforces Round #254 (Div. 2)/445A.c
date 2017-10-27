#include <stdio.h>

int main()
{
    int i, j, N, M;
    char Str[100][101];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Str[i]);
    }
    for(i = 0; i < N; ++i) {
        for(j = 0; j < M; ++j) {
            if(Str[i][j] == '.') {
                if(i & 1) {
                    if(j & 1) {
                        Str[i][j] = 'B';
                    } else {
                        Str[i][j] = 'W';
                    }
                } else {
                    if(j & 1) {
                        Str[i][j] = 'W';
                    } else {
                        Str[i][j] = 'B';
                    }
                }
            }
        }
    }
    for(i = 0; i < N; ++i) {
        puts(Str[i]);
    }
    return 0;
}
