#include <stdio.h>
#include <string.h>

int Vowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    char s[1001];
    char t[1001];
    scanf("%s %s", s, t);
    if(strlen(s) != strlen(t)) {
        puts("No");
        return 0;
    }
    for(int i = 0; s[i]; ++i) {
        if(Vowel(s[i]) != Vowel(t[i])) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
