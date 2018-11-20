#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, ans;
    int Hash[4];
    while(scanf("%d", &N) != EOF) {
        memset(Hash, 0, sizeof(Hash));
        for(i = 0; i < N; ++i) {
            scanf("%d", &ans);
            Hash[ans - 1]++;
        }
        ans = 0;
        ans += Hash[3];
        ans += Hash[2];
        Hash[0] -= Hash[2];
        if(Hash[0] < 0) {
            Hash[0] = 0;
        }
        ans += Hash[1] / 2;
        if(Hash[1] % 2) {
            ans += 1;
            Hash[0] -= 2;
            if(Hash[0] < 0) {
                Hash[0] = 0;
            }
        }
        if(Hash[0] % 4) {
            Hash[0] += 4 - Hash[0] % 4;
        }
        ans += Hash[0] / 4;
        printf("%d\n", ans);
    }
    return 0;
}
