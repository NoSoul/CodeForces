#include <stdio.h>

int main()
{
    int i, j, A, B;
    char Map[8][9];
    for(i = 0; i < 8; ++i) {
        scanf("%s", Map[i]);
    }
    A = 8;
    B = 8;
    for(i = 0; i < 8; ++i) {
        j = 0;
        while(Map[j][i] == '.' && j < 8) {
            ++j;
        }
        if(j < 8) {
            if(Map[j][i] == 'W') {
                if(j < A) {
                    A = j;
                }
            }
        }
        j = 7;
        while(Map[j][i] == '.' && j >= 0) {
            --j;
        }
        if(j >= 0) {
            if(Map[j][i] == 'B') {
                if(7 - j < B) {
                    B = 7 - j;
                }
            }
        }
    }
    puts(A <= B ? "A" : "B");
    return 0;
}
