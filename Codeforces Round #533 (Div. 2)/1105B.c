#include <stdio.h>

int Cnt[26];

int main()
{
    int n, k;
    char str[200001];
    scanf("%d %d %s", &n, &k, str);
    for(int i = 0; i < n; ++i) {
        int j;
        for(j = 0; j < k && i + j < n; ++j) {
            if(str[i + j] != str[i]) {
                break;
            }
        }
        if(j == k) {
            ++Cnt[str[i] - 'a'];
        }
        i = i + j - 1;
    }
    int level = Cnt[0];
    for(int i = 1; i < 26; ++i) {
        if(level < Cnt[i]) {
            level = Cnt[i];
        }
    }
    printf("%d\n", level);
    return 0;
}
