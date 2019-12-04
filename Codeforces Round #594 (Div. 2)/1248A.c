#include <stdio.h>

int main()
{
    int t;
    int p[100001];
    int q[100001];
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d", &n);
        long long cntA[2] = {0};
        long long cntB[2] = {0};
        for(int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            ++cntA[p[i] & 1];
        }
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) {
            scanf("%d", &q[i]);
            ++cntB[q[i] & 1];
        }
        printf("%I64d\n", cntA[0]*cntB[0] + cntA[1]*cntB[1]);
    }
    return 0;
}
