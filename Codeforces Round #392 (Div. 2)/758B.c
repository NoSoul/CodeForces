#include <stdio.h>
#include <string.h>

int main()
{
    int len;
    char Str[101];
    int Ans[4], Idx[4];
    char Ele[4] = {"RBYG"};
    scanf("%s", Str);
    len = strlen(Str);
    for(Idx[0] = 0; Idx[0] < 4; ++Idx[0]) {
        for(Idx[1] = 0; Idx[1] < 4; ++Idx[1]) {
            for(Idx[2] = 0; Idx[2] < 4; ++Idx[2]) {
                for(Idx[3] = 0; Idx[3] < 4; ++Idx[3]) {
                    if(Idx[0] != Idx[1] && Idx[0] != Idx[2] && Idx[0] != Idx[3] && Idx[1] != Idx[2] && Idx[1] != Idx[3] && Idx[2] != Idx[3]) {
                        memset(Ans, 0, sizeof(Ans));
                        char pass = 1;
                        for(int i = 0; i < len; ++i) {
                            if(Str[i] == '!') {
                                ++Ans[Idx[i & 3]];
                            } else {
                                if(Str[i] != Ele[Idx[i & 3]]) {
                                    pass = 0;
                                    break;
                                }
                            }
                        }
                        if(pass) {
                            printf("%d %d %d %d\n", Ans[0], Ans[1], Ans[2], Ans[3]);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
