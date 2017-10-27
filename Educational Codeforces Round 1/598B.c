#include <stdio.h>
#include <string.h>

int main()
{
    int i, m, l, r, k;
    char StrA[10001], StrB[10001];
    scanf("%s %d", StrA, &m);
    while(m--) {
        scanf("%d %d %d", &l, &r, &k);
        --l;
        --r;
        int len = r - l + 1;
        memcpy(StrB + l, StrA + l, len * sizeof(char));
        k %= len;
        for(i = 0; i < len; ++i) {
            StrA[l + (k + i) % len] = StrB[l + i];
        }
    }
    puts(StrA);
    return 0;
}
