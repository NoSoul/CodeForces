#include <stdio.h>
#include <stdlib.h>

typedef __int64 LL_t;

typedef struct {
    int id;
    int num;
} Node_t;
Node_t A[26];

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)b).num - (*(Node_t *)a).num;
}

char Str[100001];

int main()
{
    int N, K, i;
    LL_t Sum = 0;
    scanf("%d %d", &N, &K);
    scanf("%s", Str);
    for(i = 0; i < 26; ++i) {
        A[i].id = i;
    }
    for(i = 0; i < N; ++i) {
        ++A[Str[i] - 'A'].num;
    }
    qsort(A, 26, sizeof(Node_t), cmp);
    for(i = 0; i < 26; ++i) {
        if(K > A[i].num) {
            Sum += (LL_t)A[i].num * A[i].num;
            K -= A[i].num;
        } else {
            Sum += (LL_t)K * K;
            break;
        }
    }
    printf("%I64d\n", Sum);
    return 0;
}
