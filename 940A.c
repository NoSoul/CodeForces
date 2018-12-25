#include <stdio.h>

int Cnt[101];

int main()
{
    int n, d, x;
    scanf("%d %d", &n, &d);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        ++Cnt[x];
    }
    int min = n;
    for(int i = 1; i < 101; ++i) {
        int cur = 0;
        for(int j = 1; j < i; ++j) {
            cur += Cnt[j];
        }
        for(int j = i + d + 1; j < 101; ++j) {
            cur += Cnt[j];
        }
        if(min > cur) {
            min = cur;
        }
    }
    printf("%d\n", min);
    return 0;
}
