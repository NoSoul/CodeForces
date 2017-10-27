#include <stdio.h>
#include <string.h>

int main()
{
    int i, Len, Ans;
    char Str[10];
    scanf("%s", Str);
    Len = strlen(Str);
    Ans = 0;
    for(i = 0; i < Len; ++i) {
        if(Str[i] == '4') {
            Ans += 1 << (Len - i - 1);
        } else {
            Ans += 1 << (Len - i);
        }
    }
    printf("%d\n", Ans);
    return 0;
}
