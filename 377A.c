#include <stdio.h>

typedef struct {
    int x, y;
} Node_t;
Node_t Queue[250000];
int Size;
int step[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M;
char Map[500][501];
char Visited[500][501];

void BFS(int x, int y)
{
    int Head, Tail, i, k;
    Head = 0;
    Tail = 1;
    Size  = 1;
    Queue[0].x = x;
    Queue[0].y = y;
    Visited[x][y] = 1;
    while(Head < Tail) {
        for(i = Head; i < Tail; ++i) {
            Node_t next;
            for(k = 0; k < 4; ++k) {
                next.x = Queue[i].x + step[k][0];
                next.y = Queue[i].y + step[k][1];
                if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M) {
                    continue;
                }
                if(Map[next.x][next.y] == '.' && Visited[next.x][next.y] == 0) {
                    Visited[next.x][next.y] = 1;
                    Queue[Size++] = next;
                }
            }
        }
        Head = Tail;
        Tail = Size;
    }
}

int main()
{
    int K, i, j, flag;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
        Map[i][M] = '\0';
    }
    flag = 0;
    for(i = 0; i < N; ++i) {
        if(flag) {
            break;
        }
        for(j = 0; j < M; ++j) {
            if(Map[i][j] == '.') {
                BFS(i, j);
                flag = 1;
                break;
            }
        }
    }
    for(i = Size - 1, j = 0; j < K; --i, ++j) {
        Map[Queue[i].x][Queue[i].y] = 'X';
    }
    for(i = 0; i < N; ++i) {
        puts(Map[i]);
    }
    return 0;
}
