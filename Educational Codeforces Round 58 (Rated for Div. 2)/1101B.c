#include <stdio.h>
#include <string.h>

int main()
{
    char str[500001];
    scanf("%s", str);
    int len = strlen(str);
    int start = -1;
    int end = -1;
    for(int i = 0; i < len; ++i) {
        if(str[i] == '[') {
            for(int j = i + 1; j < len; ++j) {
                if(str[j] == ':') {
                    start = j;
                    break;
                }
            }
            break;
        }
    }
    for(int i = len - 1; i >= 0; --i) {
        if(str[i] == ']') {
            for(int j = i - 1; j >= 0; --j) {
                if(str[j] == ':') {
                    end = j;
                    break;
                }
            }
            break;
        }
    }
    if(start == -1 || end == -1 || start >= end) {
        puts("-1");
    } else {
        int ans = 4;
        for(int i = start + 1; i < end; ++i) {
            ans += str[i] == '|';
        }
        printf("%d\n", ans);
    }
    return 0;
}
