#include <stdio.h>

int main()
{
    char match[] = {"ROYGBIV"};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        if(i < 7) {
            printf("%c", match[i]);
        } else {
            printf("%c", match[3 + ((i - 7) & 3)]);
        }
    }
    putchar('\n');
    return 0;
}
