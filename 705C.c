#include <stdio.h>
#include <string.h>

#define MAXN    300001

char Flag[MAXN];
int Size;
int E[MAXN];
int Adj[MAXN];
int Last[MAXN];

int main()
{
    int n, q, type, x, read, maxt;
    memset(Adj, -1, sizeof(Adj));
    memset(Last, -1, sizeof(Last));
    scanf("%d %d", &n, &q);
    read = 0;
    maxt = -1;
    while(q--) {
        scanf("%d %d", &type, &x);
        if(type == 1) {
            E[Size] = Adj[x];
            Adj[x] = Size++;
        } else if(type == 2) {
            for(int i = Adj[x]; ~i; i = E[i]) {
                if(i == Last[x] || i <= maxt) {
                    break;
                }
                if(!Flag[i]) {
                    Flag[i] = 1;
                    ++read;
                }
            }
            Last[x] = Adj[x];
        } else {
            if(maxt < x - 1) {
                for(int i = maxt + 1; i < x; ++i) {
                    if(!Flag[i]) {
                        Flag[i] = 1;
                        ++read;
                    }
                }
                maxt = x - 1;
            }
        }
        printf("%d\n", Size - read);
    }
    return 0;
}
