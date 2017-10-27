#include <stdio.h>
#include <string.h>

char Map[3][101];
char Flag[3][101];

int main()
{
    int T, N, K, i, j;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &K);
        memset(Map, 0, sizeof(Map));
        for(i = 0; i < 3; ++i) {
            scanf("%s", Map[i]);
        }
        int start = 0;
        if(Map[1][0] == 's') {
            start = 1;
        }
        if(Map[2][0] == 's') {
            start = 2;
        }
        memset(Flag, 0, sizeof(Flag));
        Flag[start][0] = 1;
        char check = 0;
        for(j = 0; j < N; ++j) {
            for(i = 0; i < 3; ++i) {
                if(Flag[i][j] == 1) {
                    if(j + 1 < N) {
                        if(Map[i][j + 1] == '.') {
                            if(j + 3 < N) {
                                if(Map[i][j + 3] == '.') {
                                    Flag[i][j + 3] = 1;
                                }
                            } else {
                                check = 1;
                                break;
                            }
                            if(i > 0) {
                                if(Map[i - 1][j + 1] == '.') {
                                    if(j + 3 < N) {
                                        if(Map[i - 1][j + 3] == '.') {
                                            Flag[i - 1][j + 3] = 1;
                                        }
                                    } else {
                                        check = 1;
                                        break;
                                    }
                                }
                            }
                            if(i < 2) {
                                if(Map[i + 1][j + 1] == '.') {
                                    if(j + 3 < N) {
                                        if(Map[i + 1][j + 3] == '.') {
                                            Flag[i + 1][j + 3] = 1;
                                        }
                                    } else {
                                        check = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    } else {
                        check = 1;
                        break;
                    }
                }
            }
        }
        puts(check ? "YES" : "NO");
    }
    return 0;
}
