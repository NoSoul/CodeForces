#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int parA = 2 * sqrt(a);
    int parB = 2 * sqrt(b);
    int winSize = 5;
    for(int i = parA - winSize; i <= parA + winSize; ++i) {
        if(a < ((i + 1) / 2) * ((i + 1) / 2) && (i & 1) && i >= 1) {
            a = i;
            break;
        }
    }
    for(int i = parB - winSize; i <= parB + winSize; ++i) {
        if(b < (i / 2) * (i / 2) + i / 2 && (i & 1) == 0 && i >= 1) {
            b = i;
            break;
        }
    }
    puts(a < b ? "Vladik" : "Valera");
    return 0;
}
