#include <stdio.h>

int main()
{
    int N, i;
    double A, D;
    scanf("%lf %lf", &A, &D);
    scanf("%d", &N);
    for(i = 1; i <= N; ++i)
    {
        double temp = (double)i * D / (A * 4);
        long long num = temp;
        double dis = i * D - num * (A * 4);
        if(dis < A)
        {
            printf("%lf %lf\n", dis, 0.0);
        }
        else if(dis < 2 * A)
        {
            printf("%lf %lf\n", A, dis - A);
        }
        else if(dis < 3 * A)
        {
            printf("%lf %lf\n", 3 * A - dis, A);
        }
        else
        {
            printf("%lf %lf\n", 0.0, 4 * A - dis);
        }
    }
    return 0;
}
