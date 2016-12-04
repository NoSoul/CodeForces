#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int n, n1, n2;
    int A[100000];
    double Ans = 0;
    scanf("%d %d %d", &n, &n1, &n2);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, n, sizeof(int), cmp);
    if(n1 > n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    double sum;
    sum = 0;
    for(int i = 0; i < n1; ++i) {
        sum += A[i];
    }
    Ans = sum / n1;
    sum = 0;
    for(int i = 0; i < n2; ++i) {
        sum += A[n1 + i];
    }
    Ans += sum / n2;
    printf("%lf\n", Ans);
    return 0;
}
