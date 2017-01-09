#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d", &n);
        char Name[100][11];
        for(int i = 0; i < n; ++i) {
            scanf("%s", Name[i]);
        }
        scanf("%d\n", &m);
        char Msg[100][132];
        char Flag[100][100];
        int Cnt[100];
        int Ans[100];
        memset(Ans, -1, sizeof(Ans));
        memset(Cnt, 0, sizeof(Cnt));
        memset(Flag, 0, sizeof(Flag));
        for(int i = 0; i < m; ++i) {
            fgets(Msg[i], 131, stdin);
            if(Msg[i][0] == '?') {
                Cnt[i] = n;
                int start = 1;
                int end;
                while(Msg[i][start] != '\0') {
                    if((Msg[i][start] >= 'a' && Msg[i][start] <= 'z') || (Msg[i][start] >= 'A' && Msg[i][start] <= 'Z') || (Msg[i][start] >= '0' && Msg[i][start] <= '9')) {
                        int end = start;
                        while(Msg[i][end] != '\0') {
                            if((Msg[i][end] >= 'a' && Msg[i][end] <= 'z') || (Msg[i][end] >= 'A' && Msg[i][end] <= 'Z') || (Msg[i][end] >= '0' && Msg[i][end] <= '9')) {
                                ++end;
                            } else {
                                break;
                            }
                        }
                        char subStr[101];
                        int len = 0;
                        for(int j = start; j < end; ++j) {
                            subStr[len++] = Msg[i][j];
                        }
                        subStr[len] = '\0';
                        for(int j = 0; j < n; ++j) {
                            if(strcmp(subStr, Name[j]) == 0) {
                                if(Flag[i][j] == 0) {
                                    Flag[i][j] = -1;
                                    --Cnt[i];
                                    break;
                                }
                            }
                        }
                        start = end;
                    } else {
                        ++start;
                    }
                }
                if(Cnt[i] == 1) {
                    for(int j = 0; j < n; ++j) {
                        if(Flag[i][j] == 0) {
                            Ans[i] = j;
                            break;
                        }
                    }
                }
            } else {
                memset(Flag[i], -1, 100 * sizeof(char));
                char curName[11];
                int len = 0;
                for(int j = 0; Msg[i][j] != ':'; ++j) {
                    curName[len++] = Msg[i][j];
                }
                curName[len] = '\0';
                Cnt[i] = 1;
                for(int j = 0; j < n; ++j) {
                    if(strcmp(curName, Name[j]) == 0) {
                        Flag[i][j] = 0;
                        Ans[i] = j;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            if(Cnt[i] == 1) {
                int cur = i;
                while(cur - 1 >= 0 && Flag[cur - 1][Ans[cur]] == 0) {
                    Flag[cur - 1][Ans[cur]] = -1;
                    if(--Cnt[cur - 1] != 1) {
                        break;
                    }
                    for(int j = 0; j < n; ++j) {
                        if(Flag[cur - 1][j] == 0) {
                            Ans[cur - 1] = j;
                            break;
                        }
                    }
                    --cur;
                }
                cur = i;
                while(cur + 1 < m && Flag[cur + 1][Ans[cur]] == 0) {
                    Flag[cur + 1][Ans[cur]] = -1;
                    if(--Cnt[cur + 1] != 1) {
                        break;
                    }
                    for(int j = 0; j < n; ++j) {
                        if(Flag[cur + 1][j] == 0) {
                            Ans[cur + 1] = j;
                            break;
                        }
                    }
                    ++cur;
                }
            }
        }
        char Impossible = 0;
        for(int i = 0; i < m; ++i) {
            if(Cnt[i] == 0) {
                Impossible = 1;
            }
        }
        if(Impossible) {
            puts("Impossible");
        } else {
            for(int i = 0; i < m; ++i) {
                if(Cnt[i] != 1) {
                    for(int j = 0; j < n; ++j) {
                        if(Flag[i][j] == 0) {
                            Ans[i] = j;
                        }
                    }
                    if(i + 1 < m) {
                        if(Flag[i + 1][Ans[i]] == 0) {
                            Flag[i + 1][Ans[i]] = -1;
                        }
                    }
                }
                printf("%s:%s", Name[Ans[i]], strstr(Msg[i], ":") + 1);
            }
        }
    }
    return 0;
}
