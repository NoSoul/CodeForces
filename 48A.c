#include <stdio.h>

int Win(int a, int b)
{
    return b == (a + 1) % 3;
}

int main()
{
    char ans[4] = "FMS";
    int choice[3];
    char str[15];
    for(int i = 0; i < 3; ++i) {
        scanf("%s", str);
        if(str[0] == 'r') {
            choice[i] = 0;
        } else if(str[0] == 's') {
            choice[i] = 1;
        } else if(str[0] == 'p') {
            choice[i] = 2;
        }
    }
    for(int i = 0; i < 3; ++i) {
        char allWin = 1;
        for(int j = 0; j < 3; ++j) {
            if(i != j && !Win(choice[i], choice[j])) {
                allWin = 0;
                break;
            }
        }
        if(allWin) {
            putchar(ans[i]);
            return 0;
        }
    }
    puts("?");
    return 0;
}
