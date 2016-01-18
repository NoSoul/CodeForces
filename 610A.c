#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N & 1) {
        puts("0");
        return 0;
    }
    N /= 2;
    printf("%d\n", (N - 1) / 2);
    return 0;
}
