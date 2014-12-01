#include <stdio.h>

typedef struct
{
    int m_x, m_y;
} Node_t;
Node_t A[101];
char Flag[101][101];
int Cnt;

int Judge(Node_t a, Node_t b)
{
    if((a.m_x > b.m_x && a.m_x < b.m_y) || (a.m_y > b.m_x && a.m_y < b.m_y))
    {
        return 1;
    }
    return 0;
}

int main()
{
    int N, t, i, j, k;
    Node_t temp;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d %d %d", &t, &temp.m_x, &temp.m_y);
        if(t == 1)
        {
            for(i = 0; i < Cnt; ++i)
            {
                if(Judge(temp, A[i]))
                {
                    Flag[Cnt][i] = 1;
                }
                if(Judge(A[i], temp))
                {
                    Flag[i][Cnt] = 1;
                }
            }
            for(k = 0; k < Cnt + 1; ++k)
            {
                for(i = 0; i < Cnt + 1; ++i)
                {
                    for(j = 0; j < Cnt + 1; ++j)
                    {
                        if(Flag[i][k] && Flag[k][j])
                        {
                            Flag[i][j] = 1;
                        }
                    }
                }
            }
            A[Cnt] = temp;
            ++Cnt;
        }
        else
        {
            puts(Flag[temp.m_x - 1][temp.m_y - 1] ? "YES" : "NO");
        }
    }
    return 0;
}
