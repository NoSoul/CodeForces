#include <stdio.h>
#include <string.h>

char Map[6][2][10] = {
    {"Power", "purple"},
    {"Time", "green"},
    {"Space", "blue"},
    {"Soul", "orange"},
    {"Reality", "red"},
    {"Mind", "yellow"},
};
char flag[6];

int main()
{
    int n;
    char str[10];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < 6; ++j) {
            if(strcmp(str, Map[j][1]) == 0) {
                flag[j] = 1;
            }
        }
    }
    printf("%d\n", 6 - n);
    for(int j = 0; j < 6; ++j) {
        if(!flag[j]) {
            printf("%s\n", Map[j][0]);
        }
    }
    return 0;
}
