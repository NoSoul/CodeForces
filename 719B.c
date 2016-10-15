#include <stdio.h>

char Str[100001];

int main()
{
    int Ans, rCnt, bCnt;
    scanf("%*d %s", Str);
    rCnt = bCnt = 0;
    for(int i = 0; Str[i] != '\0'; ++i) {
        char target = i & 1 ? 'r' : 'b';
        if(Str[i] != target) {
            if(target == 'r') {
                ++bCnt;
            } else {
                ++rCnt;
            }
        }
    }
    Ans = rCnt > bCnt ? rCnt : bCnt;
    rCnt = bCnt = 0;
    for(int i = 0; Str[i] != '\0'; ++i) {
        char target = i & 1 ? 'b' : 'r';
        if(Str[i] != target) {
            if(target == 'r') {
                ++bCnt;
            } else {
                ++rCnt;
            }
        }
    }
    if(Ans > (rCnt > bCnt ? rCnt : bCnt)) {
        Ans = (rCnt > bCnt ? rCnt : bCnt);
    }
    printf("%d\n", Ans);
    return 0;
}
