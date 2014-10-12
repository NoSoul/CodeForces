#include <stdio.h>

typedef long long LL_t;

LL_t A, B, Ans;

int main()
{
    Ans = 0;
    scanf("%I64d %I64d", &A, &B);
    while(A)
    {
        if(A >= B)
        {
            Ans += A/B;
            A %= B;
        }
        else
        {
            if(B % A ==0)
            {
                Ans += B/A-1;
                B = A;
            }
            else
            {
                Ans += B/A;
                B -= (B/A)*A;
            }
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
