#include <stdio.h>

int N, M;
char Visited[20001];
int Queue[20001];

void BFS()
{
    int Head, Tail, i, Size;
    Head = 0;
    Tail = 1;
    Size = 0;
    int Ans = 0;
    Queue[Size++] = N;
    Visited[N] = 1;
    while(Head < Tail) {
        if(Visited[M]) {
            printf("%d\n", Ans);
            return;
        }
        for(i = Head; i < Tail; ++i) {
            int Num = Queue[i];
            if(Num - 1 > 0 && !Visited[Num - 1]) {
                Queue[Size++] = Num - 1;
                Visited[Num - 1] = 1;
            }
            if(Num * 2 < 20001 && !Visited[Num * 2]) {
                Queue[Size++] = Num * 2;
                Visited[Num * 2] = 1;
            }
        }
        Head = Tail;
        Tail = Size;
        ++Ans;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    BFS();
    return 0;
}
