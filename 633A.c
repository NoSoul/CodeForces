#include <stdio.h>

int main()
{
    int a, b, c, i;
    scanf("%d %d %d", &a, &b, &c);
    for(i = 0; a * i <= c; ++i) {
        if((c - a * i) % b == 0) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
