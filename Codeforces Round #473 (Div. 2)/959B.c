#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN    100000
#define MAXLEN  21

typedef struct {
    char m_Str[MAXLEN];
    int m_Cost;
} DataType_t;

DataType_t A[MAXN];
int group[MAXN];

int DataCMP(const void *a, const void *b)
{
    return strcmp(((DataType_t *)a)->m_Str, ((DataType_t *)b)->m_Str);
}

int main()
{
    char msg[21];
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", A[i].m_Str);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i].m_Cost);
    }
    for(int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        int min = 1e9;
        for(int j = 0; j < x; ++j) {
            scanf("%d", &group[j]);
            --group[j];
            if(min > A[group[j]].m_Cost) {
                min = A[group[j]].m_Cost;
            }
        }
        for(int j = 0; j < x; ++j) {
            A[group[j]].m_Cost = min;
        }
    }
    qsort(A, n, sizeof(DataType_t), DataCMP);
    long long ans = 0;
    for(int i = 0; i < m; ++i) {
        scanf("%s", msg);
        DataType_t *node = bsearch(msg, A, n, sizeof(DataType_t), DataCMP);
        ans += node->m_Cost;
    }
    printf("%I64d\n", ans);
    return 0;
}
