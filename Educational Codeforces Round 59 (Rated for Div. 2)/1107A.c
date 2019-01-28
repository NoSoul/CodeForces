#include <stdio.h>

int main()
{
    int q, n;
    char str[301];
    scanf("%d", &q);
    while(q--) {
        scanf("%d %s", &n, str);
        if(n == 2) {
            if(str[0] >= str[1]) {
                puts("NO");
            } else {
                puts("YES");
                printf("2\n%c %c\n", str[0], str[1]);
            }
        } else {
            puts("YES");
            printf("2\n%c %s\n", str[0], str + 1);
        }
    }
    return 0;
}
