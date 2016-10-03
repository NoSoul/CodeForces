#include <stdio.h>

typedef struct {
    int cnt;
    int pos;
} DataType_t;
DataType_t A[2600];
int Size;

void BinaryHeapPush(DataType_t *array, int *len, DataType_t val)
{
    ++(*len);
    int now = *len;
    while(now > 1 && val.cnt < array[now >> 1].cnt) {
        array[now] = array[now >> 1];
        now >>= 1;
    }
    array[now] = val;
}

DataType_t BinaryHeapPop(DataType_t *array, int *len)
{
    DataType_t ret = array[1];
    int now = 1, temp;
    while((now << 1) <= *len) {
        temp = now << 1;
        if((temp + 1) <= *len && array[temp + 1].cnt < array[temp].cnt) {
            ++temp;
        }
        if(array[temp].cnt < array[*len].cnt) {
            array[now] = array[temp];
        } else {
            break;
        }
        now = temp;
    }
    array[now] = array[*len];
    --(*len);
    return ret;
}

typedef struct {
    int x;
    int y;
} Point_t;
char Map[50][51];
Point_t Queue[2600];
int N, M;
int step[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
int Pos;

int BFS(int i, int j)
{
    int Head, Tail;
    Queue[Pos].x = i;
    Queue[Pos].y = j;
    Head = Pos + 0;
    Tail = Pos + 1;
    Map[i][j] = '1';
    char flag = 0;
    while(Head < Tail) {
        for(int i = 0; i < 4; ++i) {
            int xPrime = Queue[Head].x + step[i][0];
            int yPrime = Queue[Head].y + step[i][1];
            if(xPrime >= 0 && xPrime < N && yPrime >= 0 && yPrime < M) {
                if(Map[xPrime][yPrime] == '.') {
                    Queue[Tail].x = xPrime;
                    Queue[Tail].y = yPrime;
                    Map[xPrime][yPrime] = '1';
                    ++Tail;
                }
            } else {
                flag = 1;
            }
        }
        ++Head;
    }
    if(flag) {
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(Map[i][j] == '1') {
                    Map[i][j] = '0';
                }
            }
        }
        return 0;
    }
    return Tail - Pos;
}

int main()
{
    int K, Ans = 0, lake = 0;
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(Map[i][j] == '.') {
                int len = BFS(i, j);
                if(len) {
                    DataType_t cur;
                    cur.pos = Pos;
                    cur.cnt = len;
                    Pos += len;
                    BinaryHeapPush(A, &Size, cur);
                    ++lake;
                }
            }
        }
    }
    while(lake > K) {
        DataType_t cur = BinaryHeapPop(A, &Size);
        Ans += cur.cnt;
        for(int i = 0; i < cur.cnt; ++i) {
            Map[Queue[cur.pos + i].x][Queue[cur.pos + i].y] = '*';
        }
        --lake;
    }
    printf("%d\n", Ans);
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            putchar(Map[i][j] == '*' ? '*' : '.');
        }
        puts("");
    }
    return 0;
}
