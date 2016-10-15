#include <stdio.h>
#include <stdlib.h>

char Str[100001];

int main()
{
    int x, y;
    x = y = 0;
    scanf("%s", Str);
    for(int i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'L') {
            x -= 1;
        }
        if(Str[i] == 'R') {
            x += 1;
        }
        if(Str[i] == 'U') {
            y += 1;
        }
        if(Str[i] == 'D') {
            y -= 1;
        }
    }
    x = abs(x);
    y = abs(y);
    x += y;
    if(x & 1) {
        puts("-1");
    } else {
        printf("%d\n", x / 2);
    }
    return 0;
}
