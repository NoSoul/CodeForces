#include <stdio.h>

typedef struct
{
    int k;
    char visit;
    unsigned int flag[4];
} Employee_t;
Employee_t A[100];

int InSet(int i, int j)
{
    int res = 0;
    res |= A[i].flag[0] & A[j].flag[0];
    res |= A[i].flag[1] & A[j].flag[1];
    res |= A[i].flag[2] & A[j].flag[2];
    res |= A[i].flag[3] & A[j].flag[3];
    return res;
}

void Merge(int i, int j)
{
    A[i].flag[0] |= A[j].flag[0];
    A[i].flag[1] |= A[j].flag[1];
    A[i].flag[2] |= A[j].flag[2];
    A[i].flag[3] |= A[j].flag[3];
}

int main()
{
    int N, M, i, j, Num, Ans = 0, Sum = 0;
    scanf("%d %d", &N, &M);
    for(i=0; i<N; ++i)
    {
        scanf("%d", &A[i].k);
        Sum += A[i].k;
        A[i].visit = 0;
        for(j=0; j<4; ++j)
        {
            A[i].flag[j] = 0;
        }
        for(j=0; j<A[i].k; ++j)
        {
            scanf("%d", &Num);
            --Num;
            if(Num < 32)
            {
                A[i].flag[0] |= 1<<Num;
            }
            else if(Num < 64)
            {
                A[i].flag[1] |= 1<<(Num-32);
            }
            else if(Num < 96)
            {
                A[i].flag[2] |= 1<<(Num-64);
            }
            else
            {
                A[i].flag[3] |= 1<<(Num-96);
            }
        }
    }
    if(Sum == 0)
    {
        printf("%d\n", N);
        return 0;
    }
    for(i=0; i<N; ++i)
    {
        if(!A[i].visit)
        {
            ++Ans;
            while(1)
            {
                char flag = 0;
                for(j=i+1; j<N; ++j)
                {
                    if(!A[j].visit)
                    {
                        if(InSet(i, j))
                        {
                            flag = 1;
                            A[j].visit = 1;
                            Merge(i, j);
                        }
                    }
                }
                if(!flag)
                {
                    break;
                }
            }
            A[i].visit = 1;
        }
    }
    printf("%d\n", Ans-1);
    return 0;
}
