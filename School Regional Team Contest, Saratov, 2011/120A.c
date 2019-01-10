#include <stdio.h>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[5];
    int a;
    scanf("%s", str);
    if(str[0] == 'f') {
        scanf("%d", &a);
        puts(a == 1 ? "L" : "R");
    } else {
        scanf("%d", &a);
        puts(a == 1 ? "R" : "L");
    }
    return 0;
}
