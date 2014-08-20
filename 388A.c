#include <stdio.h>

int Hash[101];
int Ans[101];

int main()
{
    int N, i, Num, j, Len;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &Num);
        ++Hash[Num];
    }
    for(i=0; i<Hash[0]; ++i)
    {
        Ans[i] = 1;
    }
    Len = Hash[0];
    for(i=1; i<101; ++i)
    {
        if(Hash[i])
        {
            for(j=0; j<Len; ++j)
            {
                if(Hash[i] > i+1-Ans[j])
                {
                    Hash[i] -= i+1-Ans[j];
                    Ans[j] = i+1;
                }
                else
                {
                    Ans[j] += Hash[i];
                    Hash[i] = 0;
                    break;
                }
            }
            while(Hash[i])
            {
                if(Hash[i] > i+1)
                {
                    Hash[i] -= i+1;
                    Ans[Len++] = i+1;
                }
                else
                {
                    Ans[Len++] = Hash[i];
                    Hash[i] = 0;
                }
            }
        }
    }
    printf("%d\n", Len);
    return 0;
}
