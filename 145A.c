#include <stdio.h>

#define MAXN    100001

int main()
{
    int i, A, B;
    char StrA[MAXN], StrB[MAXN];
    scanf("%s %s", StrA, StrB);
    A = B = 0;
    for(i = 0; StrA[i] != '\0'; ++i) {
        if(StrB[i] != StrA[i]) {
            if(StrA[i] == '4') {
                ++A;
            } else {
                ++B;
            }
        }
    }
    if(A < B) {
        printf("%d\n", B);
    } else {
        printf("%d\n", A);
    }
    return 0;
}
