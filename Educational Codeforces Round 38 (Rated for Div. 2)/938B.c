#include <stdio.h>

int main()
{
    int n, a;
    scanf("%d", &n);
    int maxA = 0, minB = 1e6, sumA = 0, sumB = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a <= 500000) {
            if(maxA < a) {
                maxA = a;
                sumA = a - 1;
            }
        } else {
            if(minB > a) {
                minB = a;
                sumB = 1e6 - a;
            }
        }
    }
    printf("%d\n", sumA > sumB ? sumA : sumB);
    return 0;
}
