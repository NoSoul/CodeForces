#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", (x + 6) / 7);
    }
    return 0;
}
