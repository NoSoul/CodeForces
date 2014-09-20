#include <stdio.h>

int main()
{
    int N, p, q, Ans;
    scanf("%d", &N);
    Ans = 0;
    while(N--)
    {
        scanf("%d %d", &p, &q);
        if(p+2 <= q)
        {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
