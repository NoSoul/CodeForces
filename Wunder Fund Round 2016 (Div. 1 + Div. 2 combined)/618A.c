#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 31; i >= 0; i--) {
        if(1 << i & n) {
            printf("%d ", i + 1);
        }
    }
    puts("");
    return 0;
}
