#include <stdio.h>

int flag[8];

int main()
{
    char Map[8][9];
    int i, j, Ans = 0;
    for(i = 0; i < 8; ++i) {
        scanf("%s", Map[i]);
    }
    for(i = 0; i < 8; ++i) {
        for(j = 0; j < 8; ++j) {
            if(Map[j][i] == 'W') {
                break;
            }
        }
        if(j == 8) {
            flag[i] = 1;
            ++Ans;
        }
    }
    for(i = 0; i < 8; ++i) {
        for(j = 0; j < 8; ++j) {
            if(Map[i][j] == 'B' && !flag[j]) {
                ++Ans;
                break;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
