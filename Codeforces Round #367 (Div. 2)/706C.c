#include <stdio.h>
#include <string.h>
#define MAXN    100001

typedef struct {
    int start;
    int length;
} Str_t;

int C[MAXN];
char StrMap[MAXN];
Str_t Info[MAXN];
char Bad[MAXN][2];
long long Dp[MAXN][2];

int Check(int u, int v, int revU, int revV)
{
    int startU = Info[u].start;
    int endU = Info[u].start + Info[u].length;
    int offsetU = 1;
    if(revU) {
        startU = Info[u].start + Info[u].length - 1;
        endU = Info[u].start - 1;
        offsetU = -1;
    }
    int startV = Info[v].start;
    int endV = Info[v].start + Info[v].length;
    int offsetV = 1;
    if(revV) {
        startV = Info[v].start + Info[v].length - 1;
        endV = Info[v].start - 1;
        offsetV = -1;
    }
    for(int i = startU, j = startV; i != endU && j != endV; i += offsetU, j += offsetV) {
        if(StrMap[i] > StrMap[j]) {
            return 0;
        } else if(StrMap[i] < StrMap[j]) {
            return 1;
        }
    }
    if(Info[u].length > Info[v].length) {
        return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &C[i]);
    }
    Info[0].start = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%s", StrMap + Info[i].start);
        Info[i].length = strlen(StrMap + Info[i].start);
        Info[i + 1].start = Info[i].start + Info[i].length;
    }
    Dp[0][0] = 0;
    Dp[0][1] = C[0];
    for(int i = 1; i < n; ++i) {
        Bad[i][0] = Bad[i][1] = 1;
        if(Check(i - 1, i, 0, 0) && !Bad[i - 1][0]) {
            Dp[i][0] = Dp[i - 1][0];
            Bad[i][0] = 0;
        }
        if(Check(i - 1, i, 1, 0) && !Bad[i - 1][1]) {
            if((!Bad[i][0] && Dp[i][0] > Dp[i - 1][1]) || Bad[i][0]) {
                Dp[i][0] = Dp[i - 1][1];
                Bad[i][0] = 0;
            }
        }
        if(Check(i - 1, i, 0, 1) && !Bad[i - 1][0]) {
            Dp[i][1] = Dp[i - 1][0] + C[i];
            Bad[i][1] = 0;
        }
        if(Check(i - 1, i, 1, 1) && !Bad[i - 1][1]) {
            if((!Bad[i][1] && Dp[i][1] > Dp[i - 1][1] + C[i]) || Bad[i][1]) {
                Dp[i][1] = Dp[i - 1][1] + C[i];
                Bad[i][1] = 0;
            }
        }
    }
    if(Bad[n - 1][0] && Bad[n - 1][1]) {
        puts("-1");
    } else {
        long long ans;
        if(!Bad[n - 1][0] && !Bad[n - 1][1]) {
            ans = Dp[n - 1][0] < Dp[n - 1][1] ? Dp[n - 1][0] : Dp[n - 1][1];
        } else if(!Bad[n - 1][0]) {
            ans = Dp[n - 1][0];
        } else {
            ans = Dp[n - 1][1];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
