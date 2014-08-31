#include <stdio.h>

int GCD(int a, int b)
{
    int temp;
    while(b)
    {
        temp = a;
        a = b;
        b = temp%b;
    }
    return a;
}

int main()
{
    int N, i, Max, g;
    int A[100];
    Max = 1;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i]);
        if(i == 0)
        {
            g = A[0];
        }
        else
        {
            g = GCD(g, A[i]);
        }
        if(A[i] > Max)
        {
            Max = A[i];
        }
    }
    puts((Max/g-N)&1?"Alice":"Bob");
    return 0;
}
