#include <stdio.h>

int main()
{
    int n, c, d, delta = 0;
    int min, max, lastRound;
    char knowMax, knowMin;
    scanf("%d", &n);
    knowMax = knowMin = 0;
    min = -200001 * 100;
    max = 200001 * 100;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &c, &d);
        if(d == 1) {
            if(!knowMin) {
                knowMin = 1;
                min = 1900 - delta;
            } else {
                if(lastRound == 2 && min > 1900 - delta) {
                    min = 1900 - delta;
                }
            }
            if(min > max || (knowMax && max + delta < 1900)) {
                puts("Impossible");
                return 0;
            }
        } else {
            if(!knowMax) {
                knowMax = 1;
                max = 1899 - delta;
            } else {
                if(max > 1899 - delta) {
                    max = 1899 - delta;
                }
            }
            if(min > max || (knowMin && min + delta > 1899)) {
                puts("Impossible");
                return 0;
            }
        }
        delta += c;
        lastRound = d;
    }
    if(!knowMax) {
        puts("Infinity");
    } else {
        printf("%d\n", max + delta);
    }
    return 0;
}
