#include <stdio.h>

int main()
{
    int A, B, C, exp, Ans;
    scanf("%d %d %d", &A, &B, &C);
    Ans = A+B+C;
    exp = (A+B)*C;
    if(exp > Ans)
    {
        Ans = exp;
    }
    exp = A*(B+C);
    if(exp > Ans)
    {
        Ans = exp;
    }
    exp = A*B*C;
    if(exp > Ans)
    {
        Ans = exp;
    }
    printf("%d\n", Ans);
    return 0;
}
