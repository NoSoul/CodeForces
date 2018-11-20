#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1)

int R[100];

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int main()
{
    int N, i, Ans;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &R[i]);
    }
    qsort(R, N, sizeof(int), cmp);
    for(Ans = i = 0; i < N; i += 2) {
        Ans += R[i] * R[i] - R[i + 1] * R[i + 1];
    }
    if(i + 1 == N) {
        Ans += R[i] * R[i];
    }
    printf("%f\n", Ans * PI);
    return 0;
}
