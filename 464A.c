#include <stdio.h>
#include <string.h>

int N, P;
char Str[1001];

int Check(int id)
{
    int i;
    for(i = Str[id] + 1; i < 'a' + P; ++i)
    {
        if(id > 1)
        {
            if(i != Str[id - 1] && i != Str[id - 2])
            {
                Str[id] = i;
                return 1;
            }
        }
        else if(id == 1)
        {
            if(i != Str[id - 1])
            {
                Str[id] = i;
                return 1;
            }
        }
        else
        {
            Str[id] = i;
            return 1;
        }
    }
    return 0;
}

void Update(int id)
{
    int i;
    for(i = 'a'; i < 'a' + P; ++i)
    {
        if(id > 1)
        {
            if(i != Str[id - 1] && i != Str[id - 2])
            {
                Str[id] = i;
                return;
            }
        }
        else if(id == 1)
        {
            if(i != Str[id - 1])
            {
                Str[id] = i;
                return;
            }
        }
        else
        {
            Str[id] = i;
            return;
        }
    }
}

int main()
{
    int Len, i;
    scanf("%d %d", &N, &P);
    scanf("%s", Str);
    Len = strlen(Str);
    int start = Len - 1;
    while(Check(start) == 0)
    {
        --start;
    }
    if(start >= 0)
    {
        for(i = start + 1; i < Len; ++i)
        {
            Update(i);
        }
        puts(Str);
    }
    else
    {
        puts("NO");
    }
    return 0;
}
