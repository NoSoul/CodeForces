#include <stdio.h>

int LastPos[26];
char Flag[26];

int main()
{
    int n, k;
    char str[1000001];
    scanf("%d %d %s", &n, &k, str);
    for(int i = 0; i < n; ++i) {
        LastPos[str[i] - 'A'] = i;
    }
    for(int i = 0; i < n; ++i) {
        if(!Flag[str[i] - 'A']) {
            Flag[str[i] - 'A'] = 1;
            --k;
            if(k < 0) {
                puts("YES");
                return 0;
            }
        }
        if(LastPos[str[i] - 'A'] == i) {
            ++k;
        }
    }
    puts("NO");
    return 0;
}
