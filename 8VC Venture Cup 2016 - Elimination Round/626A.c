#include <stdio.h>
#include <string.h>

char Flag[401][401];

int main()
{
    int N, i, j, Ans = 0;
    char Str[201];
    scanf("%d %s", &N, Str);
    for(i = 0; i < N; ++i) {
        memset(Flag, 0, sizeof(Flag));
        int x = 200, y = 200;
        Flag[x][y] = 1;
        for(j = i; j < N; ++j) {
            if(Str[j] == 'U') {
                --x;
            } else if(Str[j] == 'D') {
                ++x;
            } else if(Str[j] == 'L') {
                --y;
            } else {
                ++y;
            }
            if(Flag[x][y]) {
                ++Ans;
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
