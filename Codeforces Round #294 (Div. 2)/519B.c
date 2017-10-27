#include <stdio.h>

int main()
{
    int N, i, Num, A = 0, B = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &Num);
        A ^= Num;
    }
    for(i = 0; i < N - 1; ++i) {
        scanf("%d", &Num);
        A ^= Num;
        B ^= Num;
    }
    for(i = 0; i < N - 2; ++i) {
        scanf("%d", &Num);
        B ^= Num;
    }
    printf("%d\n%d\n", A, B);
    return 0;
}
