#include <stdio.h>
#include <string.h>

int main()
{
    int  N, Plus, Minus, a, b, c, d, e, Max, Now;
    char Name[21], Ans[21];
    scanf("%d", &N);
    scanf("%s %d %d %d %d %d %d %d", Name, &Plus, &Minus, &a, &b, &c, &d, &e);
    strcpy(Ans, Name);
    Max = Plus * 100 - Minus * 50 + a + b + c + d + e;
    while(--N) {
        scanf("%s %d %d %d %d %d %d %d", Name, &Plus, &Minus, &a, &b, &c, &d, &e);
        Now = Plus * 100 - Minus * 50 + a + b + c + d + e;
        if(Max < Now) {
            Max = Now;
            strcpy(Ans, Name);
        }
    }
    puts(Ans);
    return 0;
}
