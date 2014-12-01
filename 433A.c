#include <stdio.h>

int main()
{
    int N, i, Num;
    int A[3] = {0};
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%d", &Num);
        Num /= 100;
        ++A[Num];
    }
    if(A[1] == 0)
    {
        if((A[2] & 1) == 0)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    else
    {
        if((A[1] & 1) == 0)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
