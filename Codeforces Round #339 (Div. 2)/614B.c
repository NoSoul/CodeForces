#include <stdio.h>
#include <string.h>

char Num[100001];
char Leader[100001];

int Beautiful(const char *str)
{
    int i, j = 0;
    for(i = 0; str[i] != '\0'; ++i) {
        if(str[i] > '1') {
            return 0;
        } else if(str[i] == '1') {
            if(++j == 2) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int N, i, Cnt = 0;
    scanf("%d", &N);
    Leader[0] = '1';
    for(i = 0; i < N; ++i) {
        scanf("%s", Num);
        if(strlen(Num) == 1 && Num[0] == '0') {
            puts("0");
            return 0;
        }
        if(!Beautiful(Num)) {
            memcpy(Leader, Num, strlen(Num) + 1);
        } else {
            Cnt += strlen(Num) - 1;
        }
    }
    printf("%s", Leader);
    for(i = 0; i < Cnt; ++i) {
        putchar('0');
    }
    putchar('\n');
    return 0;
}
