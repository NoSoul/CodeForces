#include <stdio.h>

char Map[3][3];
char InDegree[3];
char Visit[3];

int main()
{
    char str[4];
    for(int i = 0; i < 3; ++i) {
        scanf("%s", str);
        if(str[1] == '<') {
            Map[str[0] - 'A'][str[2] - 'A'] = 1;
            ++InDegree[str[2] - 'A'];
        } else {
            Map[str[2] - 'A'][str[0] - 'A'] = 1;
            ++InDegree[str[0] - 'A'];
        }
    }
    char ans[4];
    int size = 0;
    while(1) {
        char find = 0;
        for(int i = 0; i < 3; ++i) {
            if(!Visit[i] && InDegree[i] == 0) {
                find = 1;
                Visit[i] = 1;
                ans[size++] = i + 'A';
                for(int j = 0; j < 3; ++j) {
                    if(Map[i][j]) {
                        --InDegree[j];
                    }
                }
                break;
            }
        }
        if(!find) {
            break;
        }
    }
    if(size == 3) {
        printf("%c%c%c\n", ans[0], ans[1], ans[2]);
    } else {
        puts("Impossible");
    }
    return 0;
}
