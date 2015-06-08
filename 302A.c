#include <stdio.h>

int main()
{
    int N, M, i, L, R, Num, A, B;
    scanf("%d %d", &N, &M);
    for(A = B = i = 0; i < N; ++i) {
        scanf("%d", &Num);
        A += (Num == 1);
        B += (Num == -1);
    }
    while(M--) {
        scanf("%d %d", &L, &R);
        if(((R - L + 1) & 1) == 0 && A >= (R - L + 1) / 2 && B >= (R - L + 1) / 2) {
            puts("1");
            continue;
        }
        puts("0");
    }
}
