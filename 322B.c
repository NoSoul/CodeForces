#include <stdio.h>

#define MIN(a,b)	((a)<(b)?(a):(b))

int main()
{
    int i, Ans = 0, Min;
    int A[3], B[3];
    for(i = 0; i < 3; ++i)
    {
        scanf("%d", &A[i]);
        Ans += A[i] / 3;
        B[i] = A[i] % 3;
    }
    Min = 0;
    if(B[0] > 0 && B[1] > 0 && B[2] > 0)
    {
        Min = MIN(MIN(B[0], B[1]), B[2]);
    }
    else if(B[0] + B[1] == 4 && A[2] > 2)
    {
        Min = 1;
    }
    else if(B[0] + B[2] == 4 && A[1] > 2)
    {
        Min = 1;
    }
    else if(B[1] + B[2] == 4 && A[0] > 2)
    {
        Min = 1;
    }
    printf("%d\n", Ans + Min);
    return 0;
}
