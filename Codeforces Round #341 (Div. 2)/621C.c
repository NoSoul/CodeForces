#include <stdio.h>

typedef struct {
    int l;
    int r;
} Node_t;
Node_t A[100000];

int GetNum(int l, int r, int p)
{
    int a = l / p;
    int b = r / p;
    return b - a + (a * p == l && a != 0);
}

int main()
{
    int N, P, i;
    double ratio = 0.0;
    scanf("%d %d", &N, &P);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &A[i].l, &A[i].r);
    }
    for(i = 0; i < N; ++i) {
        int p, n;
        p = (i - 1 + N) % N;
        n = (i + 1) % N;
        int a[3][2];
        a[0][0] = A[p].r - A[p].l + 1;
        a[0][1] = GetNum(A[p].l, A[p].r, P);
        a[1][0] = A[i].r - A[i].l + 1;
        a[1][1] = GetNum(A[i].l, A[i].r, P);
        a[2][0] = A[n].r - A[n].l + 1;
        a[2][1] = GetNum(A[n].l, A[n].r, P);
        double fa = (double)2.0 * a[1][1] * a[0][0] * a[2][0];
        double fb = (double)a[0][0] * a[1][0] * a[2][0];
        fa += (double)a[0][1] * (a[1][0] - a[1][1]) * (a[2][0] - a[2][1]);
        fa += (double)a[2][1] * (a[1][0] - a[1][1]) * (a[0][0] - a[0][1]);
        fa += (double)2.0 * (a[1][0] - a[1][1]) * a[0][1] * a[2][1];
        ratio += 1.0 * fa / fb;
    }
    printf("%lf\n", ratio * 1000);
    return 0;
}
