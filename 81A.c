#include <stdio.h>

#define  MaxL 200010

char Stack[MaxL];

int main()
{
    int Top, i;
    Top = 0;
    do
    {
        scanf("%c", &Stack[Top]);
        if(Top != 0)
        {
            if(Stack[Top] == Stack[Top - 1])
            {
                Top -= 2;
            }
        }
        ++Top;
    }
    while(Stack[Top - 1] != '\n');
    for(i = 0; i < Top - 1; ++i)
    {
        printf("%c", Stack[i]);
    }
    printf("\n");
    return 0;
}
