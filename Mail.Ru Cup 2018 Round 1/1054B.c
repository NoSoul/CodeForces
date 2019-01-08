#include <stdio.h>

int main()
{
    int n, a;
    int pre = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a > pre + 1) {
            printf("%d\n", i + 1);
            return 0;
        }
        if(pre < a) {
            pre = a;
        }
    }
    puts("-1");
    return 0;
}
