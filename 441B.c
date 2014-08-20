#include <stdio.h>

int A[3002];

int main()
{
    int N, V, a, b, i, Sum;
    scanf("%d %d", &N, &V);
    for(i=0; i<N; ++i)
    {
        scanf("%d %d", &a, &b);
        A[a] += b;
    }
    int need, have, min;
    for(i=3001; i>0; --i)
    {
        if(A[i] < V && A[i-1] > 0)
        {
            need = V - A[i];
            have = A[i-1];
            min = need < have ? need : have;
            A[i] += min;
            A[i-1] -= min;
        }
        else if(A[i] > V)
        {
            A[i] = V;
        }
    }
    for(Sum=i=0; i<3002; ++i)
    {
        Sum += A[i];
    }
    printf("%d\n", Sum);
    return 0;
}
