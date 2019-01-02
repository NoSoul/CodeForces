#include <stdio.h>

int Cnt[101];

int main()
{
    int n, r, l;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &r);
        while(r--) {
            scanf("%d", &l);
            ++Cnt[l];
        }
    }
    for(int i = 1; i < 101; ++i) {
        if(Cnt[i] == n) {
            printf("%d ", i);
        }
    }
    return 0;
}
