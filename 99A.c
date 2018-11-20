#include <stdio.h>

char Str[1001], Ans[1001];

int main()
{
    int i, j, k;
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] != '0') {
            break;
        }
    }
    for(j = i, k = 0; Str[j] != '.'; ++j) {
        Ans[k++] = Str[j];
    }
    if(k == 0) {
        Ans[k++] = '0';
    }
    if(Ans[k - 1] == '9') {
        puts("GOTO Vasilisa.");
        return 0;
    }
    if(Str[j + 1] < '5') {
        puts(Ans);
        return 0;
    }
    ++Ans[k - 1];
    puts(Ans);
    return 0;
}
