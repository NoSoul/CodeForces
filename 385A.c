#include <stdio.h>

int main()
{
    int n, c, i, max = 0;
    int A[100];
    scanf("%d %d", &n, &c);
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < n - 1; ++i)
    {
        if(A[i] - A[i + 1] - c > max)
        {
            max = A[i] - A[i + 1] - c;
        }
    }
    printf("%d\n", max);
    return 0;
}
