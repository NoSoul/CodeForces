#include <stdio.h>
#include <string.h>

unsigned char A[100];
unsigned char B[100];

int main()
{
    int M, S, i, R;
    scanf("%d %d", &M, &S);
    if(M == 1 && S == 0) {
        puts("0 0");
        return 0;
    }
    A[0] = 1;
    R = S - 1;
    for(i = M - 1; i >= 0 && R > 0; --i) {
        int want = 9 - A[i];
        if(R > want) {
            A[i] = 9;
            R -= want;
        } else {
            A[i] += R;
            R = 0;
        }
    }
    if(R != 0) {
        puts("-1 -1");
        return 0;
    }
    R = S;
    for(i = 0; i < M && R > 0; ++i) {
        int want = 9 - B[i];
        if(R > want) {
            B[i] = 9;
            R -= want;
        } else {
            B[i] += R;
            R = 0;
        }
    }
    if(R != 0) {
        puts("-1 -1");
        return 0;
    }
    for(i = 0; i < M; ++i) {
        printf("%d", A[i]);
    }
    printf(" ");
    for(i = 0; i < M; ++i) {
        printf("%d", B[i]);
    }
    puts("");
    return 0;
}
