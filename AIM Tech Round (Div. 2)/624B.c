#include <stdio.h>

int Bad(int *array, int i, int n)
{
    if(array[i] == 0) {
        return 0;
    }
    int j;
    for(j = 0; j < n; ++j) {
        if(i != j) {
            if(array[j] == array[i]) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int N, i;
    long long Ans = 0;
    int A[26];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; ++i) {
        while(Bad(A, i, N)) {
            --A[i];
        }
        Ans += A[i];
    }
    printf("%I64d\n", Ans);
    return 0;
}
