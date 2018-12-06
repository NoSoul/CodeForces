#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int m_Idx;
    int m_Val;
} Node_t;
Node_t A[2001];
char Flag[2001];

int cmp(const void *a, const void *b)
{
    if(((Node_t *)a)->m_Val == ((Node_t *)b)->m_Val) {
        return ((Node_t *)a)->m_Idx - ((Node_t *)b)->m_Idx;
    }
    return ((Node_t *)b)->m_Val - ((Node_t *)a)->m_Val;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i].m_Val);
        A[i].m_Idx = i;
    }
    qsort(A, n, sizeof(Node_t), cmp);
    int sum = 0;
    for(int i = 0; i < k; ++i) {
        Flag[A[i].m_Idx] = 1;
        sum += A[i].m_Val;
    }
    printf("%d\n", sum);
    int cnt = 0;
    char skipFirst = 1;
    for(int i = 0; i < n; ++i) {
        if(Flag[i]) {
            if(skipFirst) {
                skipFirst = 0;
            } else {
                printf("%d ", cnt);
                cnt = 0;
            }
        }
        ++cnt;
    }
    printf("%d", cnt);
    puts("");
    return 0;
}
