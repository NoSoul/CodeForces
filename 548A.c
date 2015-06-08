#include <stdio.h>
#include <string.h>

int Palindrome(char *str, int s, int e)
{
    while(s < e) {
        if(str[s] != str[e]) {
            return 0;
        }
        ++s;
        --e;
    }
    return 1;
}

int main()
{
    char Str[1001];
    int K, L, i, M;
    scanf("%s %d", Str, &K);
    L = strlen(Str);
    if(L % K) {
        puts("NO");
        return 0;
    }
    M = L / K;
    for(i = 0; i < L; i += M) {
        if(!Palindrome(Str, i, i + M - 1)) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
