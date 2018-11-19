#include <stdio.h>

int main()
{
    int n, i;
    char hard = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &i);
        hard |= i;
    }
    puts(hard ? "HARD" : "EASY");
    return 0;
}
