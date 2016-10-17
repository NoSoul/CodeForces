#include <stdio.h>

int main()
{
    int k, r;
    scanf("%d %d", &k, &r);
    for(int i = 1; i < 10; ++i) {
        if((i * k) % 10 == r) {
            printf("%d\n", i);
            return 0;
        }
    }
    for(int i = 1; i < 11; ++i) {
        if((i * k) % 10 == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
