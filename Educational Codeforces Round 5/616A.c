#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, lenA, lenB;
    char StrA[1000001];
    char StrB[1000001];
    scanf("%s %s", StrA, StrB);
    lenA = strlen(StrA);
    lenB = strlen(StrB);
    for(i = 0; StrA[i] == '0'; ++i);
    for(j = 0; StrB[j] == '0'; ++j);
    if(lenA - i < lenB - j) {
        puts("<");
        return 0;
    }
    if(lenA - i > lenB - j) {
        puts(">");
        return 0;
    }
    for(; StrA[i] != '\0'; ++i, ++j) {
        if(StrA[i] < StrB[j]) {
            puts("<");
            return 0;
        }
        if(StrA[i] > StrB[j]) {
            puts(">");
            return 0;
        }
    }
    puts("=");
    return 0;
}
