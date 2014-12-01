#include <stdio.h>

int main()
{
    int T, x = 0;
    char str[4];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str);
        x = str[1] == '+' ? ++x : --x;
    }
    printf("%d\n", x);
    return 0;
}
