#include <stdio.h>
#include <string.h>
#define MAXN    61
#define MAXV    (MAXN*2)
char Map[MAXV][MAXV] = {0};

int BFS(int s, int e)
{
    int Queue[MAXV];
    int Head, Tail;
    Head = 0;
    Tail = 1;
    Queue[Head] = s;
    char Visit[MAXV] = {0};
    Visit[s] = 1;
    int ans = 1;
    while(Head < Tail) {
        int cur = Tail;
        for(int j = Head; j < Tail; ++j) {
            for(int i = 0; i < MAXV; ++i) {
                if(Map[Queue[j]][i]) {
                    if(!Visit[i]) {
                        Visit[i] = 1;
                        Queue[cur++] = i;
                        if(i == e) {
                            return ans;
                        }
                    }
                }
            }
        }
        Head = Tail;
        Tail = cur;
        ++ans;
    }
    return 0x3f3f3f3f;
}

int main()
{
    int n;
    long long a[100001];
    scanf("%d", &n);
    int cnt[MAXN] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        for(int j = 0; j < MAXN; ++j) {
            if(a[i] & (1LL << j)) {
                ++cnt[j];
            }
        }
    }
    for(int i = 0; i < MAXN; ++i) {
        if(cnt[i] >= 3) {
            puts("3");
            return 0;
        }
    }
    int m = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i]) {
            a[m++] = a[i];
        }
    }
    n = m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i] & a[j]) {
                Map[i][j] = Map[j][i] = 1;
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i != j) {
                if(Map[i][j] == 1) {
                    Map[i][j] = Map[j][i] = 0;
                    int cur = BFS(i, j);
                    if(ans > cur) {
                        ans = cur;
                    }
                    Map[i][j] = Map[j][i] = 1;
                }
            }
        }
    }
    if(ans == 0x3f3f3f3f) {
        puts("-1");
    } else {
        printf("%d\n", ans + 1);
    }
    return 0;
}
