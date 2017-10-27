#include <stdio.h>

int main()
{
    int N, i;
    scanf("%d", &N);
    printf("%d", N);
    for(i = 1; i < N; ++i) {
        printf(" %d", i);
    }
    printf("\n");
    return 0;
}
