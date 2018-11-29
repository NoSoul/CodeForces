#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b, c;
} Node_t;
Node_t Data[100001];

int cmp(const void *p, const void *q)
{
    return ((Node_t *)q)->c - ((Node_t *)p)->c;
}

int main()
{
    int n, m, cnt = 0;
    long long sum = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &Data[i].a, &Data[i].b);
        Data[i].c = Data[i].a - Data[i].b;
        sum += Data[i].a;
    }
    qsort(Data, n, sizeof(Node_t), cmp);
    for(int i = 0; i < n; ++i) {
        if(sum <= m) {
            break;
        }
        sum -= Data[i].c;
        ++cnt;
    }
    if(sum <= m) {
        printf("%d\n", cnt);
    } else {
        printf("%d\n", -1);
    }
    return 0;
}
