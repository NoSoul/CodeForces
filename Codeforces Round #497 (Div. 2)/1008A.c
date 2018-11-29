#include <stdio.h>
#include <string.h>

int IsVowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    char str[101];
    int ok = 1;
    scanf("%s", str);
    for(int i = 1; str[i] != '\0'; ++i) {
        if(IsVowel(str[i - 1]) || str[i - 1] == 'n') {
            continue;
        } else {
            if(!IsVowel(str[i])) {
                ok = 0;
                break;
            }
        }
    }
    int len = strlen(str);
    if(!IsVowel(str[len - 1]) && str[len - 1] != 'n') {
        ok = 0;
    }
    puts(ok ? "YES" : "NO");
    return 0;
}
