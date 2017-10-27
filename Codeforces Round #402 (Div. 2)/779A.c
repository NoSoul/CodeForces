#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int a[100], b[100];
    int cntA[5], cntB[5];
    scanf("%d", &n);
    memset(cntA, 0, sizeof(cntA));
    memset(cntB, 0, sizeof(cntB));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++cntA[a[i] - 1];
        ++cntB[a[i] - 1];
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        ++cntB[b[i] - 1];
    }
    int ans = 0;
    for(int i = 0; i < 5; ++i) {
        if(cntB[i] & 1) {
            puts("-1");
            return 0;
        }
        if(cntA[i] != cntB[i] / 2) {
            ans += abs(cntB[i] / 2 - cntA[i]);
        }
    }
    printf("%d\n", ans / 2);
    return 0;
}
