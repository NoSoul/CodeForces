#include <stdio.h>

char Str[1000001];

int main()
{
    int i, A, B;
    scanf("%s", Str);
    for(A = B = i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'x') {
            ++A;
        } else {
            ++B;
        }
    }
    if(A >= B) {
        A -= B;
        for(i = 0; i < A; ++i) {
            printf("x");
        }
    } else {
        B -= A;
        for(i = 0; i < B; ++i) {
            printf("y");
        }
    }
    return 0;
}
