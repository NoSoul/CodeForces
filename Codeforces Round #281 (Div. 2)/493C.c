#include <stdio.h>
#include <stdlib.h>

int A[200000];
int B[200000];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int Binary(int *src, int len, int key)
{
    int Left = 0;
    int Right = len - 1;
    while(Left < Right) {
        int Mid = (Left + Right) >> 1;
        if(src[Mid] > key) {
            Right = Mid;
        } else {
            Left = Mid + 1;
        }
    }
    if(src[Left] <= key) {
        ++Left;
    }
    return Left;
}

int main()
{
    int N, M, i;
    int Max, SumA, SumB, AnsA, AnsB;
    int C[2] = {0, 2000000001};
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    for(i = 0; i < M; ++i) {
        scanf("%d", &B[i]);
    }
    qsort(A, N, sizeof(int), cmp);
    qsort(B, M, sizeof(int), cmp);
    Max = 2 * N - 3 * M - 1;
    AnsA = 0;
    for(i = 0; i < N; ++i) {
        int choice = A[i];
        int idx;
        idx = Binary(A, N, choice);
        SumA = idx * 2 + (N - idx) * 3;
        idx = Binary(B, M, choice);
        SumB = idx * 2 + (M - idx) * 3;
        if(SumA - SumB > Max || (SumA - SumB == Max && SumA > AnsA)) {
            Max = SumA - SumB;
            AnsA = SumA;
            AnsB = SumB;
        }
    }
    for(i = 0; i < M; ++i) {
        int choice = B[i];
        int idx;
        idx = Binary(A, N, choice);
        SumA = idx * 2 + (N - idx) * 3;
        idx = Binary(B, M, choice);
        SumB = idx * 2 + (M - idx) * 3;
        if(SumA - SumB > Max || (SumA - SumB == Max && SumA > AnsA)) {
            Max = SumA - SumB;
            AnsA = SumA;
            AnsB = SumB;
        }
    }
    for(i = 0; i < 2; ++i) {
        int choice = C[i];
        int idx;
        idx = Binary(A, N, choice);
        SumA = idx * 2 + (N - idx) * 3;
        idx = Binary(B, M, choice);
        SumB = idx * 2 + (M - idx) * 3;
        if(SumA - SumB > Max || (SumA - SumB == Max && SumA > AnsA)) {
            Max = SumA - SumB;
            AnsA = SumA;
            AnsB = SumB;
        }
    }
    printf("%d:%d\n", AnsA, AnsB);
    return 0;
}
