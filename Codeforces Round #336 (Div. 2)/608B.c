#include <stdio.h>
#include <string.h>

#define MAXN    200002

int Cnt[2][MAXN];
char StrA[MAXN];
char StrB[MAXN];

int main()
{
    int i, lenA, lenB;
    long long Ans = 0;
    scanf("%s %s", StrA, StrB);
    for(i = 0; StrA[i] != '\0'; ++i) {
        if(i) {
            Cnt[0][i] = Cnt[0][i - 1];
            Cnt[1][i] = Cnt[1][i - 1];
        }
        ++Cnt[StrA[i] - '0'][i];
    }
    lenA = strlen(StrA);
    lenB = strlen(StrB);
    for(i = 0; i < lenB; ++i) {
        int b, e;
        if(i + lenA - 1 < lenB) {
            b = 0;
        } else {
            b = lenA - lenB + i;
        }
        if(i >= lenA - 1) {
            e = lenA - 1;
        } else {
            e = i;
        }
        int cur = StrB[i] - '0';
        if(b == 0) {
            Ans += Cnt[cur ^ 1][e];
        } else {
            Ans += Cnt[cur ^ 1][e] - Cnt[cur ^ 1][b - 1];
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
