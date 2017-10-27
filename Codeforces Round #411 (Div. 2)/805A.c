#include <stdio.h>
#include <math.h>

int main()
{
    int l, r;
    scanf("%d %d", &l, &r);
    if(l != r) {
        printf("%d\n", 2);
    } else {
        int bound = sqrt(l);
        for(int i = 2; i <= bound; ++i) {
            if(l % i == 0) {
                printf("%d\n", i);
                return 0;
            }
        }
        printf("%d\n", l);
    }
    return 0;
}
