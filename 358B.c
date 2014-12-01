#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN	100001

char *Str[MAXN];

int Fun(char *str, int index)
{
    int i, j;
    for(i = j = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == Str[index][j])
        {
            ++j;
            if(Str[index][j] == '\0')
            {
                return i + 1;
            }
        }
    }
    return -1;
}

int main()
{
    char temp[MAXN];
    int N, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
    {
        scanf("%s", temp);
        if(i == 0)
        {
            Str[i] = (char*)malloc(sizeof(char) * (strlen(temp) + 5));
            memcpy(Str[i], "<3", sizeof(char) * 2);
            memcpy(Str[i] + 2, temp, strlen(temp));
            memcpy(Str[i] + 2 + strlen(temp), "<3", sizeof(char) * 2);
            Str[i][2 + strlen(temp) + 2] = '\0';
        }
        else
        {
            Str[i] = (char*)malloc(sizeof(char) * (strlen(temp) + 3));
            memcpy(Str[i], temp, strlen(temp));
            memcpy(Str[i] + strlen(temp), "<3", sizeof(char) * 2);
            Str[i][strlen(temp) + 2] = '\0';
        }
    }
    scanf("%s", temp);
    for(i = j = 0; temp[i] != '\0' && j < N; ++j)
    {
        int ret = Fun(temp + i, j);
        i += ret;
        if(ret == -1)
        {
            puts("no");
            return 0;
        }
    }
    puts(j == N ? "yes" : "no");
    return 0;
}
