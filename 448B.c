#include <stdio.h>
#include <string.h>

int HashA[26];
int HashB[26];

int main()
{
    char StrA[101];
    char StrB[101];
    int i, j, LenB, LenA;
    scanf("%s %s", StrA, StrB);
    for(LenA=i=0; StrA[i]!='\0'; ++i,++LenA)
    {
        ++HashA[StrA[i]-'a'];
    }
    for(LenB=i=0; StrB[i]!='\0'; ++i,++LenB)
    {
        ++HashB[StrB[i]-'a'];
    }
    for(i=0; i<26; ++i)
    {
        if(HashA[i] < HashB[i])
        {
            puts("need tree");
            return 0;
        }
    }
    for(i=0; i<26; ++i)
    {
        if(HashA[i] != HashB[i])
        {
            break;
        }
    }
    if(i == 26)
    {
        puts("array");
        return 0;
    }
    int k = 0;
    for(j=0; StrB[j]!='\0'; ++j)
    {
        for(i=k; StrA[i]!='\0'; ++i)
        {
            if(StrA[i] == StrB[j])
            {
                k=i+1;
                break;
            }
        }
        if(i==LenA)
        {
            puts("both");
            return 0;
        }
    }
    puts("automaton");
    return 0;
}
