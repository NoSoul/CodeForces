#include <stdio.h>

typedef struct {
    long long l;
    long long r;
} Seg_t;

void Intersect(Seg_t A, Seg_t B, Seg_t *C)
{
    C->l = A.l > B.l ? A.l : B.l;
    C->r = A.r < B.r ? A.r : B.r;
}

int Cover(Seg_t A, long long a)
{
    return a >= A.l && a <= A.r;
}

long long Length(Seg_t A)
{
    if(A.l <= A.r) {
        return A.r - A.l + 1;
    }
    return 0;
}

int main()
{
    long long k;
    Seg_t A, B, C;
    scanf("%I64d %I64d %I64d %I64d %I64d", &A.l, &A.r, &B.l, &B.r, &k);
    Intersect(A, B, &C);
    printf("%I64d\n", Length(C) - Cover(C, k));
    return 0;
}
