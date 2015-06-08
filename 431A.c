#include <stdio.h>

int main()
{
    int A[4];
    int i, Sum;
    char Str[100001];
    for(i = 0; i < 4; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%s", Str);
    for(Sum = i = 0; Str[i] != '\0'; ++i) {
        Sum += A[Str[i] - '1'];
    }
    printf("%d\n", Sum);
    return 0;
}
