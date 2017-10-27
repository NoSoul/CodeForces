#include <stdio.h>

int main()
{
    int N;
    char flag = 0;
    char Map[1000][6];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
        if(!flag) {
            if(Map[i][0] == 'O' && Map[i][1] == 'O') {
                flag = 1;
                Map[i][0] = Map[i][1] = '+';
            } else if(Map[i][3] == 'O' && Map[i][4] == 'O') {
                flag = 1;
                Map[i][3] = Map[i][4] = '+';
            }
        }
    }
    puts(flag ? "YES" : "NO");
    if(flag) {
        for(int i = 0; i < N; ++i) {
            puts(Map[i]);
        }
    }
    return 0;
}
