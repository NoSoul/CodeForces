#include <stdio.h>
#include <string.h>

char Src[100001], Dst[100001];
int CntS[26], CntD[26];

int main()
{
    int i, Cnt;
    scanf("%s %s", Src, Dst);
    if(strlen(Src) != strlen(Dst)) {
        puts("NO");
        return 0;
    }
    for(Cnt = i = 0; Src[i] != '\0'; ++i) {
        ++CntS[Src[i] - 'a'];
        ++CntD[Dst[i] - 'a'];
        if(Src[i] != Dst[i]) {
            ++Cnt;
        }
    }
    for(i = 0; i < 26; ++i) {
        if(CntS[i] != CntD[i]) {
            break;
        }
    }
    puts((Cnt == 2 && i == 26) ? "YES" : "NO");
    return 0;
}
