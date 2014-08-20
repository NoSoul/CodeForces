#include <stdio.h>

int main()
{
    int T, i, j, k, Cnt;
    int table[6] = {12,6,4,3,2,1};
    int Hash[6] = {0};
    char Str[13];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", Str);
        Cnt = 0;
        for(i=0; i<6; ++i)
        {
            for(j=0; j<table[i]; ++j)
            {
                int flag = 1;
                for(k=0; k<12/table[i]; ++k)
                {
                    flag &= Str[k*table[i]+j]=='X';
                }
                if(flag)
                {
                    break;
                }
            }
            Hash[i] = (j!=table[i]);
            Cnt += Hash[i];
        }
        printf("%d ", Cnt);
        for(i=0; i<6; ++i)
        {
            if(Hash[i])
            {
                printf("%dx%d ", 12/table[i], table[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
