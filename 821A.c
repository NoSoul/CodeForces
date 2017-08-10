#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int Map[50][50];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &Map[i][j]);
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(Map[i][j] != 1) {
                char find = 0;
                for(int k = 0; k < n; ++k) {
                    for(int l = 0; l < n; ++l) {
                        if(Map[i][j] == Map[i][k] + Map[l][j]) {
                            find = 1;
                            break;
                        }
                    }
                }
                if(!find) {
                    puts("No");
                    return 0;
                }
            }
        }
    }
    puts("Yes");
    return 0;
}
