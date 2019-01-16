#include <stdio.h>
#include <string.h>

int MinVal[8];

int GetIdx(char *str)
{
    int ret = 0;
    for(int i = 0; str[i]; ++i) {
        ret |= 1 << (str[i] - 'A');
    }
    return ret;
}

int main()
{
    int n, c;
    char str[4];
    for(int i = 0; i < 8; ++i) {
        MinVal[i] = 400000;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &c, str);
        int idx = GetIdx(str);
        if(MinVal[idx] > c) {
            MinVal[idx] = c;
        }
    }
    int ans = MinVal[7];
    if(ans > MinVal[1] + MinVal[2] + MinVal[4]) {
        ans = MinVal[1] + MinVal[2] + MinVal[4];
    }
    for(int i = 1; i < 7; ++i) {
        for(int j = 1; j < 7; ++j) {
            if((i | j) == 7) {
                if(ans > MinVal[i] + MinVal[j]) {
                    ans = MinVal[i] + MinVal[j];
                }
            }
        }
    }
    printf("%d\n", ans >= 400000 ? -1 : ans);
    return 0;
}
