#include <stdio.h>

int IsVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main()
{
    int n;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n && str[i]; ++i) {
        if(IsVowel(str[i])) {
            putchar(str[i]);
            int j;
            for(j = i + 1; j < n && str[j]; ++j) {
                if(!IsVowel(str[j])) {
                    putchar(str[j]);
                    break;
                }
            }
            i = j;
        } else {
            putchar(str[i]);
        }
    }
    putchar('\n');
    return 0;
}
