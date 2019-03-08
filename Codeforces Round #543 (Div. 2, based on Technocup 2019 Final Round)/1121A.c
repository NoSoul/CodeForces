#include <stdio.h>

int Max[101];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int P[101], S[101];
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &P[i]);
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &S[i]);
        if(Max[S[i]] == 0 || P[Max[S[i]]] < P[i]) {
            Max[S[i]] = i;
        }
    }
    int c, ans = 0;
    for(int i = 0; i < k; ++i) {
        scanf("%d", &c);
        if(Max[S[c]] != c) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
