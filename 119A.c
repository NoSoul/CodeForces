#include <stdio.h>

int GCD(int a, int b)
{
    int temp;
    while(b)
    {
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    int A, B, N, C;
    while(scanf("%d %d %d", &A, &B, &N) != EOF)
    {
        while(1)
        {
            C = GCD(A, N);
            if(N >= C)
            {
                N -= C;
            }
            else
            {
                puts("1");
                break;
            }
            C = GCD(B, N);
            if(N >= C)
            {
                N -= C;
            }
            else
            {
                puts("0");
                break;
            }
        }
    }
    return 0;
}
