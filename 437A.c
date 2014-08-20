#include <stdio.h>
#include <string.h>

int Check(int id, int *Len)
{
    int i;
    for(i=0; i<4; ++i)
    {
        if(i==id)
        {
            continue;
        }
        if(Len[i] < 2*Len[id])
        {
            break;
        }
    }
    if(i==4)
    {
        return 1;
    }
    for(i=0; i<4; ++i)
    {
        if(i==id)
        {
            continue;
        }
        if(2*Len[i] > Len[id])
        {
            break;
        }
    }
    if(i==4)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i, Ans;
    int Len[4];
    int IsAns[4] = {0};
    char Str[101];
    for(i=0; i<4; ++i)
    {
        scanf("%s", Str);
        Len[i] = strlen(Str)-2;
    }
    for(i=0; i<4; ++i)
    {
        IsAns[i] = Check(i, Len);
    }
    Ans = 0;
    for(i=0; i<4; ++i)
    {
        Ans += IsAns[i];
    }
    if(Ans == 1)
    {
        for(i=0; i<4; ++i)
        {
            if(IsAns[i])
            {
                printf("%c\n", i+'A');
            }
        }
    }
    else
    {
        printf("C\n");
    }
    return 0;
}
