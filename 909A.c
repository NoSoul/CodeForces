#include <stdio.h>

int main()
{
    char first[11], last[11];
    scanf("%s %s", first, last);
    putchar(first[0]);
    int i = 1;
    while(first[i] && first[i] < last[0]) {
        putchar(first[i]);
        ++i;
    }
    putchar(last[0]);
    putchar('\n');
    return 0;
}
