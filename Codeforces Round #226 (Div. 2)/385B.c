#include <stdio.h>
#include <string.h>

int main()
{
    char Str[5001];
    int A[5001 >> 2];
    int i, Cnt = 0, Sum, Pre, Len;
    scanf("%s", Str);
    Len = strlen(Str);
    for(i = 0; i + 3 < Len; ++i) {
        if(Str[i] == 'b' && Str[i + 1] == 'e' && Str[i + 2] == 'a' && Str[i + 3] == 'r') {
            A[Cnt++] = i;
        }
    }
    Sum = Pre = 0;
    for(i = 0; i < Cnt; ++i) {
        Sum += (A[i] - Pre + 1) * (Len - A[i] - 3);
        Pre = A[i] + 1;
    }
    printf("%d\n", Sum);
    return 0;
}
