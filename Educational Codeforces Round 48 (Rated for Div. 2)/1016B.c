#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, q;
    char strS[1001];
    char strT[1001];
    int Data[1001];
    int Size = 0;
    scanf("%d %d %d %s %s", &n, &m, &q, strS, strT);
    for(int i = 0; i <= n - m; ++i) {
        if(memcmp(strS + i, strT, m) == 0) {
            Data[Size++] = i;
        }
    }
    while(q--) {
        int l, r, cur = 0;
        scanf("%d %d", &l, &r);
        --l;
        --r;
        for(int i = 0; i < Size; ++i) {
            if(Data[i] >= l && Data[i] + m - 1 <= r) {
                ++cur;
            }
        }
        printf("%d\n", cur);
    }
    return 0;
}
