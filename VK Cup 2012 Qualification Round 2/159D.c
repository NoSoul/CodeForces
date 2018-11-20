#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define HEADCHAR        '$'
#define SEPARATIONCHAR  '#'
int A[4000];
char *Manacher(char *str)
{
    int originLen = strlen(str);
    int transLen = originLen << 1;
    char *transStr = (char *)malloc(sizeof(char) * (transLen + 1));
    if(transStr == NULL) {
        return NULL;
    }
    int i;
    transStr[0] = HEADCHAR;
    transStr[1] = str[0];
    for(i = 1; i < originLen; ++i) {
        transStr[i << 1] = SEPARATIONCHAR;
        transStr[i << 1 | 1] = str[i];
    }
    transStr[transLen] = '\0';
    int *P = (int *)malloc(sizeof(int) * transLen);
    if(P == NULL) {
        return NULL;
    }
    P[0] = 0;
    int id, mx, maxLen, maxId;
    id = mx = maxLen = maxId = 0;
    for(i = 1; i < transLen; ++i) {
        if(mx > i) {
            P[i] = mx - i;
            int j = (id << 1) - i;
            if(P[i] > P[j]) {
                P[i] = P[j];
            }
        } else {
            P[i] = 0;
        }
        while(transStr[i + P[i] + 1] == transStr[i - P[i] - 1]) {
            ++P[i];
        }
        if(i + P[i] > mx) {
            id = i;
            mx = i + P[i];
        }
        if(P[i] > maxLen) {
            maxLen = P[i];
            maxId = i;
        }
    }
    if(transStr[maxId - maxLen] == SEPARATIONCHAR) {
        --maxLen;
    }
    for(i = 1; i < transLen; ++i) {
        A[i] = P[i];
    }
    free(P);
    free(transStr);
    return str;
}

int main()
{
    int i, j;
    char Str[2001];
    long long Ans = 0;
    while(scanf("%s", Str) != EOF) {
        Ans = 0;
        Manacher(Str);
        int Len = strlen(Str);
        Len = Len << 1;
        for(i = 0; i < Len - 1; ++i) {
            for(j = i + 1; j < Len; ++j) {
                int a, b, x, y;
                a = i;
                b = i + A[i];
                if(!(i & 1)) {
                    ++a;
                }
                if(!(b & 1)) {
                    --b;
                }
                if(a > b) {
                    continue;
                }
                a = (a - 1) >> 1;
                b = (b - 1) >> 1;
                x = j - A[j];
                y = j;
                if(!(x & 1)) {
                    ++x;
                }
                if(!(y & 1)) {
                    --y;
                }
                if(x > y) {
                    continue;
                }
                x = (x - 1) >> 1;
                y = (y - 1) >> 1;
                if(x < a) {
                    x = a;
                }
                if(b > y) {
                    b = y;
                }
                int cnt = 0;
                Ans += (long long)(y - x + 1) * (b - a + 1);
                if(b >= x) {
                    cnt = b - x + 1;
                    Ans -= (long long)cnt * (cnt + 1) / 2;
                }
            }
        }
        printf("%I64d\n", Ans);
    }
    return 0;
}
