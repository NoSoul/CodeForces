#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int n;
    int A[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, n, sizeof(int), cmp);
    if(A[0] == A[n / 2 - 1] && A[n / 2] == A[n - 1] && A[0] != A[n - 1]) {
        printf("YES\n%d %d\n", A[0], A[n - 1]);
    } else {
        puts("NO");
    }
    return 0;
}
