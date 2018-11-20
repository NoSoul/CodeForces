#include <stdio.h>
#include <stdlib.h>

int A[100001], B[100001];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, Cnt;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    qsort(B, N, sizeof(int), cmp);
    for(Cnt = i = 0; i < N; ++i) {
        if(A[i] != B[i]) {
            ++Cnt;
        }
    }
    if(Cnt > 2) {
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}