#include <stdio.h>

int Fun(int *A, int Mat[5][5])
{
    return Mat[A[0]][A[1]] + Mat[A[1]][A[0]] + 2 * (Mat[A[2]][A[3]] + Mat[A[3]][A[2]])
           + Mat[A[1]][A[2]] + Mat[A[2]][A[1]] + 2 * (Mat[A[3]][A[4]] + Mat[A[4]][A[3]]);
}

int main()
{
    int i, j, Max, Now;
    int Mat[5][5], A[5];
    for(i=0; i<5; ++i)
    {
        for(j=0; j<5; ++j)
        {
            scanf("%d", &Mat[i][j]);
        }
    }
    Max = 0;
    for(A[0]=0; A[0]<5; ++A[0])
    {
        for(A[1]=0; A[1]<5; ++A[1])
        {
            if(A[1] != A[0])
            {
                for(A[2]=0; A[2]<5; ++A[2])
                {
                    if(A[2]!=A[0] && A[2]!=A[1])
                    {
                        for(A[3]=0; A[3]<5; ++A[3])
                        {
                            if(A[3]!=A[0] && A[3]!=A[1] && A[3]!=A[2])
                            {
                                for(A[4]=0; A[4]<5; ++A[4])
                                {
                                    if(A[4]!=A[0] && A[4]!=A[1] && A[4]!=A[2] && A[4]!=A[3])
                                    {
                                        Now = Fun(A, Mat);
                                        if(Now > Max)
                                        {
                                            Max = Now;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", Max);
    return 0;
}
