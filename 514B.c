#include <stdio.h>

typedef struct
{
    int x, y;
} Point_t;
Point_t P[1000];
char Visited[1000];

int main()
{
    int N, i, j, X, Y, Ans = 0;
    scanf("%d %d %d", &N, &X, &Y);
    for(i = 0; i < N; ++i)
    {
        scanf("%d %d", &P[i].x, &P[i].y);
    }
    for(i = 0; i < N; ++i)
    {
        if(!Visited[i])
        {
            Visited[i] = 1;
            for(j = i + 1; j < N; ++j)
            {
                if((P[i].y - Y) * (P[j].x - X) == (P[j].y - Y) * (P[i].x - X))
                {
                    Visited[j] = 1;
                }
            }
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
