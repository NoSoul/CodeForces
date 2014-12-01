#include <stdio.h>
#include <math.h>

int N[2], P[2];

double Fun(int n)
{
    double res = 1;
    while(n)
    {
        res *= n;
        --n;
    }
    return res;
}

int main()
{
    int i, j;
    char Str[2][11];
    scanf("%s %s", Str[0], Str[1]);
    for(i = 0; i < 2; ++i)
    {
        for(j = 0; Str[i][j] != '\0'; ++j)
        {
            if(Str[i][j] == '+')
            {
                ++P[i];
            }
            else if(Str[i][j] == '-')
            {
                ++N[i];
            }
        }
    }
    if(P[1] > P[0] || N[1] > N[0])
    {
        puts("0.000000000000");
        return 0;
    }
    j = P[0] + N[0] - P[1] - N[1];
    if(j == 0)
    {
        puts("1.000000000000");
        return 0;
    }
    printf("%.12lf\n", Fun(j) / pow(2, j) / Fun(P[0] - P[1]) / Fun(N[0] - N[1]));
    return 0;
}
