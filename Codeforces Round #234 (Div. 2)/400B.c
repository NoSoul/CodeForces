#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, M, i, j, Pre, Cnt;
    char Str[1001];
    int A[1001];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Str);
        for(j = 0; Str[j] != 'G'; ++j);
        int Pos = j;
        for(; Str[j] != 'S' && Str[j] != '\0'; ++j);
        if(j == M) {
            printf("-1\n");
            return 0;
        }
        A[i] = j - Pos;
    }
    qsort(A, N, sizeof(int), cmp);
    Pre = A[0];
    Cnt = 1;
    for(i = 1; i < N; ++i) {
        if(A[i] != Pre) {
            Pre = A[i];
            ++Cnt;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
