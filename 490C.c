#include <stdio.h>
#include <string.h>

int main()
{
    char Str[1000001];
    char StrA[1000001];
    int ModBy10N[1000000];
    int dataA[11], dataB[11];
    int A, B, CurModA, CurModB, FinalModB, i, L;
    char flag = 0;
    scanf("%s %d %d", Str, &A, &B);
    for(i = 0; i < 11; ++i) {
        dataA[i] = i % A;
        dataB[i] = i % B;
    }
    FinalModB = (Str[0] - '0') % B;
    ModBy10N[0] = 1 % B;
    for(i = 1; Str[i] != '\0'; ++i) {
        FinalModB = (((long long)FinalModB * dataB[10]) % B + dataB[Str[i] - '0']) % B;
        ModBy10N[i] = ((long long)ModBy10N[i - 1] * dataB[10]) % B;
    }
    L = i;
    CurModA = (Str[0] - '0') % A;
    CurModB = (Str[0] - '0') % B;
    for(i = 1; Str[i] != '\0'; ++i) {
        if(Str[i] != '0') {
            if(CurModA == 0) {
                if((FinalModB - ((long long)CurModB * ModBy10N[L - i]) % B) % B == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        CurModA = (((long long)CurModA * dataA[10]) % A + dataA[Str[i] - '0']) % A;
        CurModB = (((long long)CurModB * dataB[10]) % B + dataB[Str[i] - '0']) % B;
    }
    puts(flag ? "YES" : "NO");
    if(flag) {
        memcpy(StrA, Str, i);
        StrA[i] = '\0';
        puts(StrA);
        puts(Str + i);
    }
    return 0;
}
