#include <stdio.h>

int main()
{
    int N, i, A, B, C, num;
    scanf("%d", &N);
    for(A = B = C = i = 0; i < N; ++i) {
        scanf("%d", &num);
        if(i % 3 == 0) {
            A += num;
        } else if(i % 3 == 1) {
            B += num;
        } else {
            C += num;
        }
    }
    if(A > B && A > C) {
        puts("chest");
    }
    if(B > A && B > C) {
        puts("biceps");
    }
    if(C > A && C > B) {
        puts("back");
    }
    return 0;
}
