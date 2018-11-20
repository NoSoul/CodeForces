#include <stdio.h>
#include <string.h>

#define LL __int64

LL F(LL N)
{
    LL  r;
    int i = 0, L;
    char Str[15];
    while(N) {
        if(N % 10) {
            Str[i++] = N % 10 + '0';
        }
        N /= 10;
    }
    Str[i] = '\0';
    L = i;
    for(r = 0, i = L - 1; i >= 0; --i) {
        r *= 10;
        r += Str[i] - '0';
    }
    return r;
}

int main()
{
    LL A, B, C, X, Y, Z;
    scanf("%I64d %I64d", &A, &B);
    C = A + B;
    X = F(A);
    Y = F(B);
    Z = F(C);
    puts(X + Y == Z ? "YES" : "NO");
    return 0;
}
