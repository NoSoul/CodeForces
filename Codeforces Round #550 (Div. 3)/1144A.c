#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char str[101];
    int cnt[26];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; str[j]; ++j) {
            ++cnt[str[j] - 'a'];
        }
        int consecutive = 0;
        for(int i = 0; i < 26; ++i) {
            if(cnt[i] > 1) {
                consecutive = 2;
                break;
            } else if(cnt[i] == 1) {
                for(int j = i + 1; j < 26; ++j) {
                    if(cnt[j] == 1) {
                        i = j;
                    } else if(cnt[j] > 1) {
                        consecutive = 2;
                        break;
                    } else {
                        break;
                    }
                }
                ++consecutive;
            }
        }
        puts(consecutive == 1 ? "Yes" : "No");
    }
    return 0;
}
