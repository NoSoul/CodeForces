#include <stdio.h>

int main()
{
    int lCnt = 0;
    int pCnt = 0;
    char str[101];
    scanf("%s", str);
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '-') {
            ++lCnt;
        } else {
            ++pCnt;
        }
    }
    puts(pCnt == 0 || lCnt % pCnt == 0 ? "YES" : "NO");
    return 0;
}
