#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 8; i >= 1; --i) {
        int num = ((1 << i) - 1) * (1 << (i - 1));
        if(n % num == 0) {
            printf("%d\n", num);
            return 0;
        }
    }
    return 0;
}
