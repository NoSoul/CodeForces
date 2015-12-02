#include <stdio.h>

int main()
{
    int i, N;
    char Str[100001];
    scanf("%d %s", &N, Str);
    for(i = 0; i < N; ++i) {
        Str[i] -= '0';
    }
    int exp = Str[0] ^ 1;
    char startFlip = 0;
    int contiguousCnt = 0, curStart = -1;
    int MaxLen = 0, MaxStart = -1;
    for(i = 1; i < N; ++i) {
        if(Str[i] != exp) {
            if(!startFlip) {
                startFlip = 1;
                curStart = i;
                contiguousCnt = 1;
            } else {
                ++contiguousCnt;
            }
            exp = Str[i];
        } else {
            startFlip = 0;
            if(MaxStart == -1) {
                MaxLen = contiguousCnt;
                MaxStart = curStart;
            }
            contiguousCnt = 0;
            exp = Str[i] ^ 1;
        }
    }
    if(MaxStart == -1 && curStart != -1) {
        MaxLen = contiguousCnt;
        MaxStart = curStart;
    }
    if(~MaxStart) {
        for(i = MaxStart; i < MaxStart + MaxLen; ++i) {
            Str[i] ^= 1;
        }
    }
    int Ans = 1;
    exp = Str[0] ^ 1;
    for(i = 1; i < N; ++i) {
        if(Str[i] == exp) {
            ++Ans;
            exp ^= 1;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
