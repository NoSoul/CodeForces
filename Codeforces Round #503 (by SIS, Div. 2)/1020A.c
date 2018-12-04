#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, h, a, b, k;
    scanf("%d %d %d %d %d", &n, &h, &a, &b, &k);
    int tA, fA, tB, fB;
    while(k--) {
        scanf("%d %d %d %d", &tA, &fA, &tB, &fB);
        if(tA == tB) {
            printf("%d\n", abs(fA - fB));
        } else {
            if(fA >= a && fA <= b) {
                printf("%d\n", abs(tA - tB) + abs(fA - fB));
            } else if(abs(fA - a) < abs(fA - b)) {
                printf("%d\n", abs(tA - tB) + abs(fA - a) + abs(a - fB));
            } else {
                printf("%d\n", abs(tA - tB) + abs(fA - b) + abs(b - fB));
            }
        }
    }
    return 0;
}
