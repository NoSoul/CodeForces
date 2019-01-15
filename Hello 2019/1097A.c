#include <stdio.h>

int main()
{
    char card[6][3];
    for(int i = 0; i < 6; ++i) {
        scanf("%s", card[i]);
    }
    for(int i = 1; i < 6; ++i) {
        if(card[i][0] == card[0][0] || card[i][1] == card[0][1]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
