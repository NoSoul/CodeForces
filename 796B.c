#include <stdio.h>

char Flag[1000001];

int main()
{
    int n, m, k, h, u, v;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &h);
        Flag[h] = 1;
    }
    int Ans = 1;
    while(k--) {
        if(Flag[Ans]) {
            break;
        }
        scanf("%d %d", &u, &v);
        if(u == Ans) {
            Ans = v;
        } else if(v == Ans) {
            Ans = u;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
