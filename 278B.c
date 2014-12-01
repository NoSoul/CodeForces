#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, Res, M;
    char Str[30][21], temp[25];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%s", Str[i]);
    }
    Res = 0;
    while(1)
    {
        M = Res;
        temp[0] = M % 26 + 'a';
        M /= 26;
        j = 1;
        while(M)
        {
            temp[j++] = (M - 1) % 26 + 'a';
            M /= 26;
        }
        temp[j++] = '\0';
        strrev(temp);
        for(i = 0; i < N; ++i)
        {
            if(strstr(Str[i], temp) != NULL)
            {
                break;
            }
        }
        if(i == N)
        {
            printf("%s\n", temp);
            break;
        }
        ++Res;
    }
    return 0;
}
