#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int scores;
    int id;
} Node_t;

int cmp(const void *a, const void *b)
{
    if(((Node_t*)a)->scores == ((Node_t*)b)->scores) {
        return ((Node_t*)a)->id - ((Node_t*)b)->id;
    }
    return ((Node_t*)b)->scores - ((Node_t*)a)->scores;
}

int main()
{
    int n;
    Node_t A[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        A[i].id = i + 1;
        A[i].scores = a + b + c + d;
    }
    qsort(A, n, sizeof(Node_t), cmp);
    for(int i = 0; i < n; ++i) {
        if(A[i].id == 1) {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}
