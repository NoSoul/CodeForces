#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, bound = 0;
    char s[200001];
    char t[200001];
    scanf("%d %d %s %s", &n, &m, s, t);
    int findWildcard = -1;
    for(int i = 0; s[i]; ++i) {
        if(s[i] == '*') {
            findWildcard = i;
            break;
        }
    }
    if(findWildcard == -1) {
        puts(strcmp(s, t) == 0 ? "YES" : "NO");
        return 0;
    }
    for(int i = 0; i < findWildcard; ++i) {
        if(t[i] == 0 || s[i] != t[i]) {
            puts("NO");
            return 0;
        }
    }
    for(int i = strlen(t) - 1, j = strlen(s) - 1; j > findWildcard; --i, --j) {
        if(i < findWildcard || s[j] != t[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
