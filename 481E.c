#include <stdio.h>

#define MAXN    200000

typedef struct
{
    int M, R;
    char Merge;
} Node_t;
Node_t A[MAXN];
int Ans[MAXN][2];
int Size;

int main()
{
    int N, Win, Num, i;
    scanf("%d", &N);
    Num = N;
    Win = 0;
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &A[i].M, &A[i].R);
        if(A[i].M > A[i].R)
        {
            ++Win;
        }
    }
    if(Win * 2 > Num)
    {
        puts("0");
        return 0;
    }
    for(i = 0; i < N; ++i)
    {
        if(A[i].M < A[i].R)
        {
            if(!A[i].Merge && i - 1 >= 0 && !A[i - 1].Merge)
            {
                if(A[i - 1].M > A[i - 1].R)
                {
                    if(A[i].M + A[i - 1].M > A[i].R + A[i - 1].R)
                    {
                        A[i - 1].Merge = 1;
                        A[i].Merge = 1;
                        Ans[Size][0] = i - 1;
                        Ans[Size++][1] = i;
                        --Num;
                        if(Win * 2 > Num)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    A[i - 1].Merge = 1;
                    A[i].Merge = 1;
                    Ans[Size][0] = i - 1;
                    Ans[Size++][1] = i;
                    --Num;
                    if(Win * 2 > Num)
                    {
                        break;
                    }
                }
            }
            if(!A[i].Merge && i + 1 < N && !A[i + 1].Merge)
            {
                if(A[i + 1].M > A[i + 1].R)
                {
                    if(A[i].M + A[i + 1].M > A[i].R + A[i + 1].R)
                    {
                        A[i].Merge = 1;
                        A[i + 1].Merge = 1;
                        Ans[Size][0] = i;
                        Ans[Size++][1] = i + 1;
                        --Num;
                        if(Win * 2 > Num)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    A[i].Merge = 1;
                    A[i + 1].Merge = 1;
                    Ans[Size][0] = i;
                    Ans[Size++][1] = i + 1;
                    --Num;
                    if(Win * 2 > Num)
                    {
                        break;
                    }
                }
            }
        }
        if(A[i].M == A[i].R)
        {
            if(!A[i].Merge && i - 1 >= 0 && !A[i - 1].Merge)
            {
                A[i - 1].Merge = 1;
                A[i].Merge = 1;
                Ans[Size][0] = i - 1;
                Ans[Size++][1] = i;
                --Num;
                if(Win * 2 > Num)
                {
                    break;
                }
            }
            if(!A[i].Merge && i + 1 < N && !A[i + 1].Merge)
            {
                A[i].Merge = 1;
                A[i + 1].Merge = 1;
                Ans[Size][0] = i;
                Ans[Size++][1] = i + 1;
                --Num;
                if(Win * 2 > Num)
                {
                    break;
                }
            }
        }
    }
    if(Win * 2 <= Num)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", Size);
    for(i = 0; i < Size; ++i)
    {
        printf("%d %d\n", Ans[i][0] + 1, Ans[i][1] + 1);
    }
    return 0;
}
