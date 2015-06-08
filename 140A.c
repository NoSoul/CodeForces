#include <stdio.h>
#include <math.h>

#define PI  acos(-1)

int main()
{
    int N, R, r;
    double A, a;
    scanf("%d %d %d", &N, &R, &r);
    if(N == 1) {
        puts(R >= r ? "YES" : "NO");
        return 0;
    }
    A = PI / N;
    a = R * sin(A) / (1 + sin(A));
    puts(a + 1e-8 >= 1.0 * r ? "YES" : "NO");
    return 0;
}
