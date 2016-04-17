#include <stdio.h>
#include <math.h>

int main()
{
    int n, b, p;
    int sumB = 0, sumP = 0;
    scanf("%d %d %d", &n, &b, &p);
    sumP += n * p;
    while(n != 1) {
        int m = log2(n);
        int k = 1 << m;
        sumB += k * b + k / 2;
        n -= k / 2;
    }
    printf("%d %d\n", sumB, sumP);
    return 0;
}
