#include <stdio.h>
#include <string.h>

#define MAXV    500
int Value[MAXV];

int main()
{
    int N, M, i, a, b, c;
    double Ans = 0;
    scanf("%d %d", &N, &M);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &Value[i]);
    }
    for(i=0; i<M; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        --a;
        --b;
        if(Ans < 1.0*(Value[a]+Value[b])/c)
        {
            Ans = 1.0*(Value[a]+Value[b])/c;
        }
    }
    printf("%.15lf\n", Ans);
    return 0;
}
