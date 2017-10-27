#include <stdio.h>

int main()
{
    int n, a, pre;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(i) {
            printf("%d ", a + pre);
        }
        pre = a;
    }
    printf("%d\n", pre);
    return 0;
}
