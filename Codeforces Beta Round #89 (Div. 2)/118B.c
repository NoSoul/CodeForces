#include <stdio.h>

void Put(int num, int N)
{
    int i;
    for(i = N * 2 - num + 1; i > 0; i -= 2) {
        printf("  ");
    }
    if(num != 1) {
        num /= 2;
        for(i = 0; i <= num; ++i) {
            printf("%d ", i);
        }
        for(i = num - 1; i > 0; --i) {
            printf("%d ", i);
        }
    }
    printf("0\n");
    return;
}

int main()
{
    int N, i, M;
    scanf("%d", &N);
    M = N * 2 + 1;
    for(i = 1; i <= M; i += 2) {
        Put(i, N);
    }
    for(i = M - 2; i >= 1; i -= 2) {
        Put(i, N);
    }
    return 0;
}
