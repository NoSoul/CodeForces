#include <stdio.h>
#include <string.h>

int Match(char *str, char *t)
{
    int cnt = 0;
    for(int i = 0; str[i] && t[i]; ++i) {
        if(str[i] != t[i]) {
            return -1;
        }
        ++cnt;
    }
    return cnt;
}

void Append(char *str, int cnt, char *t)
{
    int len = strlen(str);
    for(int i = cnt; t[i]; ++i) {
        str[len++] = t[i];
    }
}

int main()
{
    int n, k;
    char t[51];
    char str[2501] = {0};
    scanf("%d %d %s", &n, &k, t);
    int pos = 0;
    while(k) {
        char find = 0;
        for(int j = pos; str[j]; ++j) {
            int cnt = Match(str + j, t);
            if(~cnt) {
                find = 1;
                --k;
                pos = j + 1;
                Append(str, cnt, t);
                break;
            }
        }
        if(!find) {
            --k;
            pos = strlen(str) + 1;
            Append(str, 0, t);
        }
    }
    puts(str);
    return 0;
}
