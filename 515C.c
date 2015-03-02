#include <stdio.h>

int Ans[10];

int main()
{
    int N, i, j;
    char Str[20];
    scanf("%d %s", &N, Str);
    for(i = 0; Str[i] != '\0'; ++i)
    {
        int num = Str[i] - '0';
        if(num < 2)
        {
            continue;
        }
        if(num == 4)
        {
            ++Ans[3];
            Ans[2] += 2;
        }
        else if(num == 6)
        {
            ++Ans[5];
            ++Ans[3];
        }
        else if(num == 8)
        {
            ++Ans[7];
            Ans[2] += 3;
        }
        else if(num == 9)
        {
            ++Ans[7];
            Ans[3] += 2;
            ++Ans[2];
        }
        else
        {
            ++Ans[num];
        }
    }
    for(i = 9; i > 1; --i)
    {
        for(j = 0; j < Ans[i]; ++j)
        {
            printf("%d", i);
        }
    }
    puts("");
    return 0;
}
