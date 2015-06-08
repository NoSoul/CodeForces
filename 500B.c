#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char Map[300][301];
unsigned char Visited[300];
int Ans[300][300];
int Size[300];
int GroupFlag[300];

void BFS(int start, int idx)
{
    int Head, i;
    Head = 0;
    Visited[start] = 1;
    GroupFlag[start] = idx;
    Ans[idx][Size[idx]++] = start;
    while(Head < Size[idx]) {
        for(i = 0; i < N; ++i) {
            if(Map[Ans[idx][Head]][i] == '1' && !Visited[i]) {
                Visited[i] = 1;
                GroupFlag[i] = idx;
                Ans[idx][Size[idx]++] = i;
            }
        }
        ++Head;
    }
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int i;
    int A[300];
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for(i = 0; i < N; ++i) {
        scanf("%s", Map[i]);
    }
    int group = 0;
    for(i = 0; i < N; ++i) {
        if(!Visited[i]) {
            BFS(i, group);
            ++group;
        }
    }
    memset(Size, 0, sizeof(Size));
    for(i = 0; i < N; ++i) {
        Ans[GroupFlag[i]][Size[GroupFlag[i]]++] = A[i];
    }
    for(i = 0; i < group; ++i) {
        if(Size[i] > 1) {
            qsort(Ans[i], Size[i], sizeof(int), cmp);
        }
    }
    memset(Size, 0, sizeof(Size));
    for(i = 0; i < N; ++i) {
        printf("%d ", Ans[GroupFlag[i]][Size[GroupFlag[i]]++]);
    }
    puts("");
    return 0;
}
