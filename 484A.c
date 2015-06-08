#include <stdio.h>
#include <string.h>

void Fun(long long num, unsigned char *dst)
{
    while(num) {
        dst[++dst[0]] = num & 1;
        num >>= 1;
    }
}

int main()
{
    int N, Len, i;
    unsigned char StrL[64], StrR[64], Ans[64];
    long long L, R, C;
    scanf("%d", &N);
    while(N--) {
        scanf("%I64d %I64d", &L, &R);
        ++R;
        memset(StrL, 0, sizeof(StrL));
        memset(StrR, 0, sizeof(StrR));
        Fun(L, StrL);
        Fun(R, StrR);
        Ans[0] = StrR[0];
        for(i = Ans[0]; i > 0; --i) {
            if(StrR[i] == 1 && StrL[i] == 0) {
                Ans[i] = 0;
                break;
            }
            Ans[i] = StrR[i];
        }
        for(--i; i > 0; --i) {
            Ans[i] = 1;
        }
        C = 0;
        for(i = Ans[0]; i > 0; --i) {
            C <<= 1;
            C |= Ans[i];
        }
        printf("%I64d\n", C);
    }
    return 0;
}
