#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, L, Min, Max, i, Ans;
    int A[1000];
    scanf("%d %d", &N, &L);
    Min = L;
    Max = 0;
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] > Max) {
            Max = A[i];
        }
        if(A[i] < Min) {
            Min = A[i];
        }
    }
    qsort(A, N, sizeof(int), cmp);
    Ans = Min * 2;
    if((L - Max) * 2 > Ans) {
        Ans = (L - Max) * 2;
    }
    for(i = 0; i < N - 1; ++i) {
        if(A[i + 1] - A[i] >  Ans) {
            Ans = A[i + 1] - A[i];
        }
    }
    if(Ans & 1) {
        printf("%d.500000\n", Ans / 2);
    } else {
        printf("%d.000000\n", Ans / 2);
    }
    return 0;
}
