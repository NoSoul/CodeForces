#include <stdio.h>

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d\n", ((N-1)*6+5)*K);
    int i, Pre = 1;
    for(i=0; i<N; ++i)
    {
        printf("%d %d %d %d\n", K*Pre, K*(Pre+1), K*(Pre+2), K*(Pre+4));
        Pre += 6;
    }
    return 0;
}
