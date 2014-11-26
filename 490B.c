#include <stdio.h>

int g_Front[1000001];
int g_Behind[1000001];
int Ans[200001];
char Vis[1000001];

int main()
{
    int N, i, a, b;
    scanf("%d", &N);
    for(i=0; i<N; ++i)
    {
        scanf("%d %d", &a, &b);
        g_Behind[a] = b;
        g_Front[b] = a;
    }
    a = g_Behind[0];
    i = 1;
    while(1)
    {
        Ans[i] = a;
        Vis[a] = 1;
        a = g_Behind[a];
        if(a == 0)
        {
            break;
        }
        i += 2;
    }
    if(N&1)
    {
        for(i=1; i<1000001; ++i)
        {
            if(g_Behind[i] && !g_Front[i] && !Vis[i])
            {
                break;
            }
        }
        a = i;
        i = 0;
        while(1)
        {
            Ans[i] = a;
            a = g_Behind[a];
            if(a == 0)
            {
                break;
            }
            i += 2;
        }
    }
    else
    {
        a = g_Front[0];
        i = N-2;
        while(1)
        {
            Ans[i] = a;
            a = g_Front[a];
            if(a == 0)
            {
                break;
            }
            i -= 2;
        }
    }
    for(i=0; i<N; ++i)
    {
        printf("%d ", Ans[i]);
    }
    puts("");
    return 0;
}
