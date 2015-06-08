#include <stdio.h>

void Fun(int A, int B, int C)
{
    int i;
    for(i = 0; i < A; ++i) {
        printf("|");
    }
    printf("+");
    for(i = 0; i < B; ++i) {
        printf("|");
    }
    printf("=");
    for(i = 0; i < C; ++i) {
        printf("|");
    }
}

int main()
{
    int i, A, B, C, Cnt;
    char Str[303];
    scanf("%s", Str);
    A = B = C = 0;
    Cnt = 0;
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == '|') {
            ++Cnt;
        }
        if(Str[i] == '+') {
            A = Cnt;
            Cnt = 0;
        }
        if(Str[i] == '=') {
            B = Cnt;
            Cnt = 0;
        }
    }
    C = Cnt;
    if(A + B == C) {
        Fun(A, B, C);
    } else if(A - 1 + B == C + 1 && A > 1) {
        Fun(A - 1, B, C + 1);
    } else if(A + B - 1 == C + 1 && B > 1) {
        Fun(A, B - 1, C + 1);
    } else if(A + B + 1 == C - 1 && C > 1) {
        Fun(A + 1, B, C - 1);
    } else {
        printf("Impossible\n");
    }
    return 0;
}
