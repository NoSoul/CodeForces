#include <stdio.h>
#include <string.h>

int main()
{
    char Str[101];
    char Base[] = "CODEFORCES";
    int i, j, k, Len;
    scanf("%s", Str);
    Len = strlen(Str);
    for(i = j = 0; i < Len; ++i, ++j) {
        if(Str[i] != Base[j]) {
            break;
        }
    }
    for(i = Len - 1, k = 9; i >= 0 && k >= j; --i, --k) {
        if(Str[i] != Base[k]) {
            break;
        }
    }
    puts(k + 1 == j ? "YES" : "NO");
    return 0;
}
