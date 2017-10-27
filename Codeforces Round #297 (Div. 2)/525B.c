#include <stdio.h>
#include <string.h>

int GetSymmetric(int i, int N)
{
    return N - 1 - i;
}

char Str[200002];
int Cnt[200002];

int main()
{
    int Len, M, i;
    scanf("%s", Str);
    Len = strlen(Str);
    scanf("%d", &M);
    while(M--) {
        scanf("%d", &i);
        --i;
        ++Cnt[i];
        --Cnt[GetSymmetric(i, Len) + 1];
    }
    int Cur = 0;
    for(i = 0; i < Len; ++i) {
        Cur += Cnt[i];
        Cur &= 1;
        putchar(Cur ? Str[GetSymmetric(i, Len)] : Str[i]);
    }
    putchar('\n');
    return 0;
}
