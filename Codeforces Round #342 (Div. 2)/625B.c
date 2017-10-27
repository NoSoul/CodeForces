#include <stdio.h>
#include <string.h>

char StrA[100001];
char StrB[30];

int main()
{
    int i, j, Ans = 0;
    scanf("%s %s", StrA, StrB);
    for(i = 0; StrA[i]; ++i) {
        char flag = 1;
        for(j = 0; StrB[j]; ++j) {
            if(StrA[i + j] != StrB[j]) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            i += j;
            --i;
        }
        Ans += flag;
    }
    printf("%d\n", Ans);
    return 0;
}
