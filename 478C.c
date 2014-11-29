#include <stdio.h>

int main()
{
    int i, j;
    int A[3];
    long long a;
    scanf("%d %d %d", &A[0], &A[1], &A[2]);
    for(i=0; i<3; ++i)
    {
        for(j=i+1; j<3; ++j)
        {
            if(A[i] > A[j])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    a = ((long long)A[0]+A[1])*2;
    if(a < A[2])
    {
        printf("%d\n", A[0]+A[1]);
    }
    else
    {
        a = (long long)A[0]+A[1]+A[2];
        printf("%d\n", (int)(a/3));
    }
    return 0;
}
