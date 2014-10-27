#include <stdio.h>

int Visited[100001];

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    i = 1;
    while(1)
    {
        Visited[i] = 1;
        printf("%d ", i);
        if(!Visited[i+K])
        {
            Visited[i+K] = 1;
            printf("%d ", i+K);
        }
        ++i;
        K -= 2;
        if(K <= 0)
        {
            break;
        }
    }
    for(i=1; i<=N; ++i)
    {
        if(!Visited[i])
        {
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}
