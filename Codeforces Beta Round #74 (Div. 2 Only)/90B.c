#include <stdio.h>

int main()
{
    int n, m;
    char map[100][101];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", &map[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char out = 0;
            for(int k = 0; k < n; ++k) {
                if(k != i && map[i][j] == map[k][j]) {
                    out = 1;
                }
            }
            for(int k = 0; k < m; ++k) {
                if(k != j && map[i][j] == map[i][k]) {
                    out = 1;
                }
            }
            if(!out) {
                putchar(map[i][j]);
            }
        }
    }
    return 0;
}
