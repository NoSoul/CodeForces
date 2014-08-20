#include <stdio.h>

int main()
{
    int N, X, i, num, Sum;
    scanf("%d %d", &N, &X);
    for(Sum=i=0; i<N; ++i)
    {
        scanf("%d", &num);
        Sum += num;
    }
    Sum = abs(Sum);
    printf("%d\n", Sum/X+((Sum%X)?1:0));
    return 0;
}
