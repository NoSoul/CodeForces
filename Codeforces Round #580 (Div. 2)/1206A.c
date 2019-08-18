#include <stdio.h>

int main()
{
    int n, num, maxA, maxB;
    maxA = maxB = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        if(maxA < num) {
            maxA = num;
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        if(maxB < num) {
            maxB = num;
        }
    }
    printf("%d %d\n", maxA, maxB);
    return 0;
}
