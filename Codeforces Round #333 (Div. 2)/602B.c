#include <stdio.h>

#define MAXN    100000
int Next[MAXN];

int main()
{
    int N, i, Ans = 0;
    int A[MAXN];
    scanf("%d", &N);
    int start = 0;
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        if(A[i] != A[start]) {
            Next[start] = i;
            start = i;
        }
    }
    Next[start] = 0;
    if(Next[0] == 0) {
        printf("%d\n", N);
    } else {
        int s, a, b, next;
        s = 0;
        a = A[s];
        b = A[Next[s]];
        next = Next[s];
        while(1) {
            while(Next[next]) {
                if(A[Next[next]] == a || A[Next[next]] == b) {
                    next = Next[next];
                } else {
                    break;
                }
            }
            if(!Next[next]) {
                if(N - s > Ans) {
                    Ans = N - s;
                }
                break;
            } else {
                if(Next[next] - s > Ans) {
                    Ans = Next[next] - s;
                }
            }
            s = Next[s];
            a = A[s];
            b = A[Next[s]];
        }
        printf("%d\n", Ans);
    }
    return 0;
}
