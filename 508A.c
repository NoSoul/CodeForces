#include <stdio.h>

int N, M;
char Map[1001][1001];

char Get(int x, int y)
{
    if(x < 1 || y < 1 || x > N || y > M)
    {
        return 0;
    }
    return Map[x][y];
}

int Judge(int x, int y)
{
    return (Get(x, y) && Get(x, y + 1) && Get(x + 1, y) && Get(x + 1, y + 1)) ||
           (Get(x, y - 1) && Get(x, y) && Get(x + 1, y - 1) && Get(x + 1, y)) ||
           (Get(x - 1, y) && Get(x - 1, y + 1) && Get(x, y) && Get(x, y + 1)) ||
           (Get(x - 1, y - 1) && Get(x - 1, y) && Get(x, y - 1) && Get(x, y));
}

int main()
{
    int K, i, x, y;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= K; ++i)
    {
        scanf("%d %d", &x, &y);
        Map[x][y] = 1;
        if(Judge(x, y))
        {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("0");
    return 0;
}
