#include <stdio.h>

int A[26];

int main()
{
    int K, i, j, k;
    char Str[1001];
    scanf("%d %s", &K, Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        ++A[Str[i] - 'a'];
    }
    for(i = 0; i < 26; ++i)
    {
        if(A[i] % K != 0)
        {
            break;
        }
    }
    if(i < 26)
    {
        puts("-1");
    }
    else
    {
        for(i = 0; i < K; ++i)
        {
            for(j = 0; j < 26; ++j)
            {
                for(k = 0; k < A[j] / K; ++k)
                {
                    printf("%c", 'a' + j);
                }
            }
        }
    }
    return 0;
}
