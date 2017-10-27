#include <stdio.h>

int main()
{
    int N, D, L, A, B, i, j, temp, a, b, X, Y;
    scanf("%d %d %d", &N, &D, &L);
    A = (N + 1) / 2;
    B = N / 2;
    if(D < A - B * L || D > A * L - B) {
        puts("-1");
        return 0;
    }
    for(i = A; i <= L * A; ++i) {
        temp = i - D;
        if(temp >= B && temp <= B * L) {
            a = i - A;
            b = temp - B;
            for(j = 0; j < B; ++j) {
                X = Y = 1;
                if(a >= L - 1) {
                    X = L;
                    a -= L - 1;
                } else if(a && a < L - 1) {
                    X = 1 + a;
                    a = 0;
                }
                if(b >= L - 1) {
                    Y = L;
                    b -= L - 1;
                } else if(b && b < L - 1) {
                    Y = 1 + b;
                    b = 0;
                }
                printf("%d %d ", X, Y);
            }
            if(N % 2) {
                X = 1 + a;
                printf("%d", X);
            }
            break;
        }
    }
    return 0;
}
