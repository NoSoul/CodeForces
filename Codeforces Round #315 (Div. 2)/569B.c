#include <stdio.h>
#include <stdlib.h>
#define MAXN    100001
int A[MAXN];
char Flag[MAXN];
char Used[MAXN];

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        Flag[A[i]] = 1;
    }
    int start = 1;
    for(i = 0; i < N; ++i) {
        if(Used[A[i]] || A[i] > N) {
            while(Flag[start]) {
                ++start;
            }
            printf("%d ", start++);
        } else {
            Used[A[i]] = 1;
            printf("%d ", A[i]);
        }
    }
    puts("");
    return 0;
}
