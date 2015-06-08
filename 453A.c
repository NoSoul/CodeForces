#include <stdio.h>

double F(double A, int N)
{
    double ret = 1;
    while(N) {
        if(N & 1) {
            ret *= A;
        }
        A *= A;
        N >>= 1;
    }
    return ret;
}

int main()
{
    int M, N, i;
    double Ans;
    scanf("%d %d", &M, &N);
    Ans = M;
    for(i = 1; i < M; ++i) {
        Ans -= F(i * 1.0 / M, N);
    }
    printf("%lf\n", Ans);
    return 0;
}
