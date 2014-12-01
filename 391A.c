#include <stdio.h>

int main()
{
    int i, Sum = 0, Cnt = 1;
    char Str[101];
    scanf("%s", Str);
    for(i = 1; Str[i] != '\0'; ++i)
    {
        if(Str[i] == Str[i - 1])
        {
            ++Cnt;
        }
        else
        {
            Sum += !(Cnt & 1);
            Cnt = 1;
        }
    }
    Sum += !(Cnt & 1);
    printf("%d\n", Sum);
    return 0;
}
