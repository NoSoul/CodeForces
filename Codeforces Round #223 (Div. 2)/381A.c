#include <stdio.h>

int main()
{
    int A[1000];
    int N, i, Left, Right, Suma, Sumb, flag, now;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    Left = 0;
    Right = N - 1;
    Suma = Sumb = 0;
    flag = 1;
    while(Left <= Right) {
        if(A[Left] > A[Right]) {
            now = A[Left];
            ++Left;
        } else {
            now = A[Right];
            --Right;
        }
        if(flag) {
            Suma += now;
        } else {
            Sumb += now;
        }
        flag ^= 1;
    }
    printf("%d %d\n", Suma, Sumb);
    return 0;
}
