#include <stdio.h>

int main()
{
    int n;
    char str[300001];
    int cnt[26] = {0};
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        ++cnt[str[i] - 'a'];
    }
    for(int i = 0; str[i]; ++i) {
        --cnt[str[i] - 'a'];
        for(int j = 0; j < str[i] - 'a'; ++j) {
            if(cnt[j]) {
                puts("YES");
                for(int k = i + 1; str[k]; ++k) {
                    if(str[k] == j + 'a') {
                        printf("%d %d\n", i + 1, k + 1);
                        break;
                    }
                }
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
