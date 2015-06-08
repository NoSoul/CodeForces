#include <stdio.h>

int A[100001];
char Hash[100001];

int main()
{
    int N, S, T, Cnt, i;
    scanf("%d %d %d", &N, &S, &T);
    for(i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
    }
    Hash[S] = 1;
    Cnt = 0;
    while(S != T) {
        S = A[S];
        if(Hash[S]) {
            Cnt = -1;
            break;
        } else {
            Hash[S] = 1;
            ++Cnt;
        }
    }
    printf("%d\n", Cnt);
    return 0;
}
