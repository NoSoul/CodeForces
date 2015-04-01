#include <stdio.h>

#define MAXN 1000001

char Str[MAXN];
int P[MAXN];
int Cnt[MAXN];
int Size, Last;

int GetTail(int id)
{
    if(id != Size - 1)
    {
        return Cnt[id + 1];
    }
    return Last;
}

int main()
{
    int K, i;
    long long Ans = 0;
    scanf("%d %s", &K, Str);
    if(K == 0)
    {
        int Zero = 0;
        for(i = 0; Str[i] != '\0'; ++i)
        {
            if(Str[i] == '1')
            {
                Ans += (long long)Zero * (Zero + 1) / 2;
                Zero = 0;
            }
            else
            {
                ++Zero;
            }
        }
        Ans += (long long)Zero * (Zero + 1) / 2;
    }
    else
    {
        --K;
        for(i = 0; Str[i] != '\0'; ++i)
        {
            if(Str[i] == '1')
            {
                P[Size] = i;
                if(Size == 0)
                {
                    Cnt[Size] = i + 1;
                }
                else
                {
                    Cnt[Size] = P[Size] - P[Size - 1];
                }
                ++Size;
            }
        }
        Last = i - P[Size - 1];
        for(i = 0; i < Size - K; ++i)
        {
            Ans += (long long)Cnt[i] * GetTail(i + K);
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
