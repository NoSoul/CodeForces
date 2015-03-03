#include <stdio.h>
#include <string.h>

char Visited[50][50];
int step[4][2] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
int N, M;
int Ox, Oy;
char Map[50][51];

int DFS(int x, int y, int cnt)
{
    int i, j;
    int ans = 0;
    for(i = 0; i < 4; ++i)
    {
        int newx, newy;
        newx = x + step[i][0];
        newy = y + step[i][1];
        if(newx >= 0 && newx < N && newy >= 0 && newy < M)
        {
            if(!Visited[newx][newy] && Map[Ox][Oy] == Map[newx][newy])
            {
                Visited[newx][newy] = 1;
                if(cnt >= 3)
                {
                    for(j = 0; j < 4; ++j)
                    {
                        if(newx == Ox + step[j][0] && newy == Oy + step[j][1])
                        {
                            return 1;
                        }
                    }
                }
                ans |= DFS(newx, newy, cnt + 1);
            }
        }
    }
    return ans;
}

int main()
{
    int i, j;
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i)
    {
        scanf("%s", Map[i]);
    }
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            Ox = i;
            Oy = j;
            memset(Visited, 0, sizeof(Visited));
            Visited[i][j] = 1;
            if(DFS(i, j, 1))
            {
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}
