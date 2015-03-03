#include <stdio.h>
#include <string.h>

int main()
{
    char S[101];
    char T[101];
    scanf("%s %s", S, T);
    int i, L;
    L = strlen(S);
    for(i = L - 1; i >= 0; --i)
    {
        if(S[i] != 'z')
        {
            ++S[i];
            break;
        }
    }
    for(++i; i < L; ++i)
    {
        S[i] = 'a';
    }
    puts(strcmp(S, T) >= 0 ? "No such string" : S);
    return 0;
}
