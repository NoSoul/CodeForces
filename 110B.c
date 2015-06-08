#include <stdio.h>

char Base[5] = "abcd";

int main()
{
    int N, i, j;
    scanf("%d", &N);
    for(j = N / 4, i = 0; i < j; ++i) {
        printf("%s", Base);
    }
    for(N %= 4, i = 0; i < N; ++i) {
        printf("%c", Base[i % 4]);
    }
    printf("\n");
    return 0;
}
