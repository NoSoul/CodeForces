#include <stdio.h>

int main()
{
    unsigned char map[4][4];
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            scanf("%hhd", &map[i][j]);
        }
    }
    for(int i = 0; i < 4; ++i) {
        if(map[i][3] == 1) {
            if(map[(i + 1) & 3][0] || map[(i + 2) & 3][1] || map[(i + 3) & 3][2] || map[i][0] || map[i][1] || map[i][2]) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
