#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for(int i = 0; i < n; ++i) {
        printf("%d ", 1);
    }
    puts("");
    return 0;
}
