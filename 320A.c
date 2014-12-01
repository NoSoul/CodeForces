#include <stdio.h>

int main()
{
    int N, A, B, C;
    char Error = 0;
    scanf("%d", &N);
    while(N)
    {
        A = N % 10;
        B = N % 100;
        C = N % 1000;
        if(A == 1)
        {
            N /= 10;
        }
        else if(B == 14)
        {
            N /= 100;
        }
        else if(C == 144)
        {
            N /= 1000;
        }
        else
        {
            Error = 1;
            break;
        }
    }
    puts(Error ? "NO" : "YES");
    return 0;
}
