#include <stdio.h>
#include <stdlib.h>

int Pos[100001][2];

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; ++i) {
        scanf("%d", &a);
        if(Pos[a][0] == 0) {
            Pos[a][0] = i;
        } else {
            Pos[a][1] = i;
        }
    }
    long long ans = 0;
    Pos[0][0] = Pos[0][1] = 1;
    for(int i = 1; i <= n; ++i) {
        int weightA = abs(Pos[i][0] - Pos[i - 1][0]) + abs(Pos[i][1] - Pos[i - 1][1]);
        int weightB = abs(Pos[i][0] - Pos[i - 1][1]) + abs(Pos[i][1] - Pos[i - 1][0]);
        ans += weightA < weightB ? weightA : weightB;
    }
    printf("%I64d\n", ans);
    return 0;
}
