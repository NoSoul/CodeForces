#include <stdio.h>
#include <string.h>

char StrA[1000][501];
char StrB[501];

int main()
{
    int n, m, common = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%s", StrA[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%s", StrB);
        for(int j = 0; j < n; ++j) {
            if(strcmp(StrB, StrA[j]) == 0) {
                ++common;
            }
        }
    }
    n -= common;
    m -= common;
    if(common & 1) {
        ++n;
    }
    puts(n > m ? "YES" : "NO");
    return 0;
}
