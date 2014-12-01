#include <stdio.h>

void DFS(int N)
{
    int i;
    printf("%d ", N);
    if(N == 1)
    {
        return;
    }
    for(i = N / 2; i > 0; --i)
    {
        if(N % i == 0)
        {
            DFS(i);
            return;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    DFS(N);
    return 0;
}
