#include <stdio.h>

char Hash[5001];

int main()
{
    int N, i, j, Cnt;
    scanf("%d", &N);
    for(Cnt = i = 0; i < N; ++i) {
        scanf("%d", &j);
        if(j <= N && !Hash[j]) {
            Hash[j] = 1;
            ++Cnt;
        }
    }
    printf("%d\n", N - Cnt);
    return 0;
}
