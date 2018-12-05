#include <stdio.h>

int main()
{
    int n, cntA0, cntA1, cntB0, cntAll0;
    char strA[100001];
    char strB[100001];
    long long ans = 0;
    scanf("%d %s %s", &n, strA, strB);
    cntA0 = cntA1 = cntB0 = cntAll0 = 0;
    for(int i = 0; i < n; ++i) {
        if(strA[i] == '0') {
            if(strB[i] == '0') {
                ++cntAll0;
            }
            ++cntA0;
        } else {
            ++cntA1;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(strB[i] == '0') {
            ++cntB0;
            if(strA[i] == '0') {
                ans += cntA1;
            } else {
                ans += cntA0;
                ans -= cntAll0;
            }
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
