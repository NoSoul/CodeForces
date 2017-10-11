#include <stdio.h>

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a & 1) {
            puts("First");
            return 0;
        }
    }
    puts("Second");
    return 0;
}
