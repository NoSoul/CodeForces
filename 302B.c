#include <stdio.h>

typedef struct
{
    int c, t;
} Song_t;

int main()
{
    int N, M, i, now, index, Sum;
    Song_t S[100001];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &S[i].c, &S[i].t);
    }
    Sum = index = 0;
    while(M--)
    {
        scanf("%d", &now);
        if(now <= Sum)
        {
            printf("%d\n", index);
            continue;
        }
        while(now > Sum)
        {
            Sum += S[index].c * S[index].t;
            if(Sum >= now)
            {
                printf("%d\n", index + 1);
            }
            ++index;
        }
    }
    return 0;
}
