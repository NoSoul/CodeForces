#include <stdio.h>

char A[100001];
int Sum[100001];
char Str[100001];

int main()
{
    int M, i, j, L, R;
    scanf("%s", Str);
    for(i = 0; Str[i + 1] != '\0'; ++i)
    {
        A[i] = (Str[i] == Str[i + 1]);
    }
    Sum[0] = A[i++] = 0;
    for(j = 1; j < i; ++j)
    {
        Sum[j] = Sum[j - 1] + A[j - 1];
    }
    scanf("%d", &M);
    while(M--)
    {
        scanf("%d %d", &L, &R);
        --L;
        --R;
        printf("%d\n", Sum[R] - Sum[L]);
    }
    return 0;
}
