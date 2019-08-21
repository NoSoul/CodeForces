#include <stdio.h>
#include <string.h>

int Dis[101][101];
int Seq[1000001];
char Flag[1000001];
char Map[101][101];

void Floyd(int n)
{
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(Dis[i][j] > Dis[i][k] + Dis[k][j]) {
                    Dis[i][j] = Dis[i][k] + Dis[k][j];
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(Dis, 0x3f, sizeof(Dis));
    for(int i = 1; i <= n; ++i) {
        scanf("%s", Map[i] + 1);
        for(int j = 1; j <= n; ++j) {
            if(Map[i][j] == '1') {
                Dis[i][j] = 1;
            }
        }
    }
    Floyd(n);
    int m;
    scanf("%d", &m);
    int ans = 2;
    Flag[0] = 1;
    Flag[m - 1] = 1;
    for(int i = 0; i < m; ++i) {
        scanf("%d", &Seq[i]);
    }
    int last = 0;
    for(int i = 1; i < m - 1; ++i) {
        if(Dis[Seq[last]][Seq[i]] + Dis[Seq[i]][Seq[i + 1]] != Dis[Seq[last]][Seq[i + 1]] || Seq[last] == Seq[i + 1]) {
            Flag[i] = 1;
            ++ans;
            last = i;
        }
    }
    printf("%d\n", ans);
    for(int i = 0; i < m; ++i) {
        if(Flag[i]) {
            printf("%d ", Seq[i]);
        }
    }
    puts("");
    return 0;
}
