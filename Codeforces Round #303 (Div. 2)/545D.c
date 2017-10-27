#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, i, Ans = 1;
    int A[100001];
    long long totalTime = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    totalTime = A[0];
    for(i = 1; i < N; ++i) {
        if(totalTime <= A[i]) {
            ++Ans;
        } else {
            while(i < N && totalTime > A[i]) {
                ++i;
            }
            if(i < N) {
                ++Ans;
            }
        }
        totalTime += A[i];
    }
    printf("%d\n", Ans);
    return 0;
}
