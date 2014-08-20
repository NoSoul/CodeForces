#include <stdio.h>

char Str[1000001];

int main()
{
    int P, X, i, j;
    int Add, Len, Num;
    scanf("%d %d", &P, &X);
    for(i=1; i<10; ++i)
    {
        Add = 0;
        Len = 1;
        Str[0] = i;
        while(Len <= P)
        {
            Num = Str[Len-1]*X + Add;
            Add = Num /10;
            Str[Len++] = Num%10;
        }
        if(Str[P]==i && Add==0)
        {
            if(Str[P-1] == 0)
            {
                continue;
            }
            for(j=P-1; j>=0; --j)
            {
                printf("%d", Str[j]);
            }
            printf("\n");
            break;
        }
    }
    if(i == 10)
    {
        puts("Impossible");
    }
    return 0;
}
