#include <stdio.h>
#include <stdlib.h>

int A[1001];
int B[1001];
int Size;

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void Push(int x)
{
    int Now;
    Now = ++Size;
    while(Now > 1 && x > B[Now >> 1]) {
        B[Now] = B[Now >> 1];
        Now >>= 1;
    }
    B[Now] = x;
    return;
}

int Pop()
{
    int Now, temp, ret;
    ret = B[1];
    Now = 1;
    while((Now << 1) <= Size) {
        temp = Now << 1;
        if((temp + 1) <= Size && B[temp] < B[temp + 1]) {
            ++temp;
        }
        if(B[temp] > B[Size]) {
            B[Now] = B[temp];
        } else {
            break;
        }
        Now = temp;
    }
    B[Now] = B[Size];
    --Size;
    return ret;
}

int main()
{
    int N, M, i, Min, Max, temp;
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, M, sizeof(int), cmp);
    for(i = 1; i <= M; ++i) {
        B[i] = A[M - i];
    }
    temp = N;
    for(Min = i = 0; i < M && temp; ++i) {
        if(temp >= A[i]) {
            Min += A[i] * (A[i] + 1) / 2;
            temp -= A[i];
        } else {
            Min += temp * (A[i] + A[i] - temp + 1) / 2;
            break;
        }
    }
    Size = M;
    Max = 0;
    while(N--) {
        temp = Pop();
        Max += temp;
        if(temp != 1) {
            Push(temp - 1);
        }
    }
    printf("%d %d\n", Max, Min);
    return 0;
}
