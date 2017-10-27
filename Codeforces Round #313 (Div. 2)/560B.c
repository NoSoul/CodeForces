#include <stdio.h>

typedef struct {
    int a, b;
} Node_t;
Node_t A, B, C;
Node_t A1, A2;

int Fun()
{
    if(B.a <= A.a && B.b <= A.b) {
        A1.a = A.a - B.a;
        A1.b = A.b;
        A2.a = A.a;
        A2.b = A.b - B.b;
        if((C.a <= A1.a && C.b <= A1.b) || (C.a <= A1.b && C.b <= A1.a) || (C.a <= A2.a && C.b <= A2.b) || (C.a <= A2.b && C.b <= A2.a)) {
            return 1;
        }
    }
    return 0;
}


int main()
{
    scanf("%d %d", &A.a, &A.b);
    scanf("%d %d", &B.a, &B.b);
    scanf("%d %d", &C.a, &C.b);
    if(Fun()) {
        puts("YES");
        return 0;
    }
    int c = B.a;
    B.a = B.b;
    B.b = c;
    if(Fun()) {
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}
