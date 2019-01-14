#include <stdio.h>

int D[1001];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i < N; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        ++D[u];
        ++D[v];
    }
    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        ans += D[i] == 1;
    }
    printf("%d\n", ans);
    return 0;
}
