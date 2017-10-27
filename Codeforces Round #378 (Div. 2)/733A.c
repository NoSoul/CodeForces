#include <stdio.h>

int main()
{
    char Str[101];
    scanf("%s", Str);
    int pre = -1, i, Ans = 0;
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'A' || Str[i] == 'E' || Str[i] == 'I' || Str[i] == 'O' || Str[i] == 'U' || Str[i] == 'Y') {
            if(i - pre > Ans) {
                Ans = i - pre;
            }
            pre = i;
        }
    }
    if(i - pre > Ans) {
        Ans = i - pre;
    }
    printf("%d\n", Ans);
    return 0;
}
