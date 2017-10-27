#include <stdio.h>

int main()
{
    int n, m;
    char StrA[1001];
    char StrB[1001];
    scanf("%d %d %s %s", &n, &m, StrA, StrB);
    int min = 2000;
    int idx = -1;
    for(int i = 0; i + n <= m; ++i) {
        int cur = 0;
        for(int j = 0; j < n; ++j) {
            if(StrA[j] != StrB[i + j]) {
                ++cur;
            }
        }
        if(min > cur) {
            min = cur;
            idx = i;
        }
    }
    printf("%d\n", min);
    for(int j = 0; j < n; ++j) {
        if(StrA[j] != StrB[idx + j]) {
            printf("%d ", j + 1);
        }
    }
    puts("");
    return 0;
}
