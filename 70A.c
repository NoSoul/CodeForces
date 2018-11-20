#include <stdio.h>

#define MOD 1000003

int main()
{
    int i, N, Sum = 1;
    scanf("%d", &N);
    for(i = 1; i < N; ++i) {
        Sum *= 3;
        Sum %= MOD;
    }
    printf("%d\n", Sum);
    return 0;
}
