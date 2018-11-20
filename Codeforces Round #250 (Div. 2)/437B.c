#include <stdio.h>
#include <stdlib.h>

#define LowBit(x) ((x)&(-x))

typedef struct {
    int id;
    int val;
} Node_t;
Node_t A[100000];
int Ans[100000];
int Size;

int cmp(const void *a, const void *b)
{
    return (*(Node_t *)b).val - (*(Node_t *)a).val;
}

int main()
{
    int sum, limit, i;
    for(i = 1; i <= 100000; ++i) {
        A[i - 1].id = i;
        A[i - 1].val = LowBit(i);
    }
    qsort(A, 100000, sizeof(Node_t), cmp);
    scanf("%d %d", &sum, &limit);
    for(i = 0; i < 100000; ++i) {
        if(sum >= A[i].val && A[i].id <= limit) {
            sum -= A[i].val;
            Ans[Size++] = A[i].id;
        }
    }
    if(sum) {
        puts("-1");
        return 0;
    }
    printf("%d\n", Size);
    for(i = 0; i < Size; ++i) {
        printf("%d ", Ans[i]);
    }
    puts("");
    return 0;
}
