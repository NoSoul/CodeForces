#include <stdio.h>
#include <string.h>

int  X[10];

void F(char *data, int len)
{
    int CP = 0, DP = 1, nowlen = len, i;
    while(CP >= 0 && CP < nowlen)
    {
        if(data[CP] >= '0' && data[CP] <= '9')
        {
            ++X[data[CP] - '0'];
            CP += DP;
            if(CP < 0 || CP >= nowlen)
            {
                return;
            }
            if(data[CP - DP] == '0')
            {
                for(i = CP - DP; i < nowlen - 1; ++i)
                {
                    data[i] = data[i + 1];
                }
                data[--nowlen] = '\0';
                CP = DP == 1 ? CP - 1 : CP;
            }
            else
            {
                --data[CP - DP];
            }
        }
        else
        {
            DP = data[CP] == '<' ? -1 : 1;
            CP += DP;
            if(CP < 0 || CP >= nowlen)
            {
                return;
            }
            if(data[CP] == '>' || data[CP] == '<')
            {
                for(i = CP - DP; i < nowlen - 1; ++i)
                {
                    data[i] = data[i + 1];
                }
                data[--nowlen] = '\0';
                CP = DP == 1 ? CP - 1 : CP;
            }
        }
    }
    return;
}

int main()
{
    int N, Q, L, R, i, j;
    char Str[102], Temp[102];
    scanf("%d %d %s", &N, &Q, Str + 1);
    while(Q--)
    {
        scanf("%d %d", &L, &R);
        for(i = L, j = 0; i <= R; ++i)
        {
            Temp[j++] = Str[i];
        }
        Temp[j] = '\0';
        F(Temp, j);
        for(i = 0; i < 10; ++i)
        {
            printf("%d ", X[i]);
            X[i] = 0;
        }
        printf("\n");
    }
    return 0;
}
