#include <stdio.h>

char Hash[1001];

int main()
{
    int N, M, i, j;
    scanf("%d %d", &N, &M);
    while(M--) {
        scanf("%d %d", &i, &j);
        Hash[i] = 1;
        Hash[j] = 1;
    }
    for(i = 1; i <= N; ++i) {
        if(Hash[i] == 0) {
            break;
        }
    }
    printf("%d\n", N - 1);
    for(j = 1; j <= N; ++j) {
        if(i != j) {
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}
