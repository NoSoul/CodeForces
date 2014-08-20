#include <stdio.h>

int main()
{
    int N, i, j, Min, num;
    int A[100];
    int Item[100];
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i]);
    }
    Min = 0x7fffffff;
    for(i=0; i<N; ++i)
    {
        int sum = 0;
        for(j=0; j<A[i]; ++j)
        {
            scanf("%d", &num);
            sum += 15+5*num;
        }
        if(sum < Min)
        {
            Min = sum;
        }
    }
    printf("%d\n", Min);
    return 0;
}
