#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
char Visited[9];
int Cur[8];
typedef struct {
    int m_Data[8];
    int m_id;
    int m_Fun;
} Node_t;
Node_t Ans[40320];
int Size;

int Fun()
{
    int i, j, ans = 0;
    for(i = 0; i < N; ++i) {
        int num = Cur[i];
        for(j = i; j < N; ++j) {
            if(Cur[j] < num) {
                num = Cur[j];
            }
            ans += num;
        }
    }
    return ans;
}

void DFS(int cnt)
{
    int i;
    if(cnt == N) {
        Ans[Size].m_id = Size;
        for(i = 0; i < N; ++i) {
            Ans[Size].m_Data[i] = Cur[i];
        }
        Ans[Size].m_Fun = Fun();
        ++Size;
    }
    for(i = 1; i <= N; ++i) {
        if(!Visited[i]) {
            Visited[i] = 1;
            Cur[cnt] = i;
            DFS(cnt + 1);
            Visited[i] = 0;
        }
    }
}

int cmp(const void *a, const void *b)
{
    if(((Node_t *)a)->m_Fun == ((Node_t *)b)->m_Fun) {
        return ((Node_t *)a)->m_id - ((Node_t *)b)->m_id;
    }
    return ((Node_t *)b)->m_Fun - ((Node_t *)a)->m_Fun;
}

int main()
{
    int i, M;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; ++i) {
        memset(Visited, 0, sizeof(Visited));
        Visited[i] = 1;
        Cur[0] = i;
        DFS(1);
    }
    qsort(Ans, Size, sizeof(Node_t), cmp);
    for(i = 0; i < N; ++i) {
        printf("%d ", Ans[M - 1].m_Data[i]);
    }
    puts("");
    return 0;
}
