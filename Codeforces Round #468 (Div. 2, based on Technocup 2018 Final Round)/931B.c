#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    --a;
    --b;
    for(int i = 1; (1 << i) < n; ++i) {
        if(a / (1 << i) == b / (1 << i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("Final!\n");
    return 0;
}
