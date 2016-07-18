#include <stdio.h>

char Flag[4];

int main()
{
    int n;
    char str[10];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n; ++i) {
        int num = str[i] - '0';
        if(num >= 1 && num <= 3) {
            Flag[0] = 1;
        }
        if(num == 7 || num == 0 || num == 9) {
            Flag[1] = 1;
        }
        if(num == 1 || num == 4 || num == 7 || num == 0) {
            Flag[2] = 1;
        }
        if(num == 3 || num == 6 || num == 9 || num == 0) {
            Flag[3] = 1;
        }
    }
    puts(Flag[0]&Flag[1]&Flag[2]&Flag[3] ? "YES" : "NO");
    return 0;
}
