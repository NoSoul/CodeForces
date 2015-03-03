#include <stdio.h>

int Map[26][26];
int D[26];

int main()
{
    int N, i, j, Len;
    char Ans[27];
    char Name[100][101];
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%s", Name[i]);
    }
    for(i = 1; i < N; ++i)
    {
        for(j = 0; Name[i][j] != '\0' && Name[i - 1][j] != '\0'; ++j)
        {
            if(Name[i][j] != Name[i - 1][j])
            {
                if(!Map[Name[i - 1][j] - 'a'][Name[i][j] - 'a'])
                {
                    Map[Name[i - 1][j] - 'a'][Name[i][j] - 'a'] = 1;
                    ++D[Name[i][j] - 'a'];
                }
                break;
            }
        }
        if(Name[i][j] == '\0' && Name[i - 1][j] != '\0')
        {
            puts("Impossible");
            return 0;
        }
    }
    Len = 0;
    while(1)
    {
        int flag = 0;
        for(i = 0; i < 26; ++i)
        {
            if(D[i] == 0)
            {
                D[i] = -1;
                flag = 1;
                Ans[Len++] = i + 'a';
                for(j = 0; j < 26; ++j)
                {
                    if(Map[i][j])
                    {
                        Map[i][j] = 0;
                        --D[j];
                    }
                }
            }
        }
        if(!flag)
        {
            break;
        }
    }
    Ans[26] = '\0';
    puts(Len == 26 ? Ans : "Impossible");
    return 0;
}
