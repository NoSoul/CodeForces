#include <stdio.h>

int main()
{
    int n, a, b;
    long long sumA = 0, maxB[2];
    scanf("%d", &n);
    maxB[0] = maxB[1] = -1;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sumA += a;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b);
        if(b > maxB[0]) {
            maxB[0] = b;
        }
        if(maxB[0] > maxB[1]) {
            long long temp = maxB[0];
            maxB[0] = maxB[1];
            maxB[1] = temp;
        }
    }
    puts(sumA <= maxB[0] + maxB[1] ? "YES" : "NO");
    return 0;
}
