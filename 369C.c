#include <stdio.h>

#define MAXN	100001

typedef struct
{
    int mV;
    int mNext;
    char mType;
} Edge_t;
Edge_t E[MAXN<<1];
int Adj[MAXN],Size;

typedef struct
{
    int mIndex;
    int mValue;
} Node_t;
Node_t Queue[MAXN];
char Visited[MAXN];
char Updated[MAXN];
char Stored[MAXN];
int AnsCnt,Ans[MAXN];


void Init(int N)
{
    int i;
    for(Size=i=0; i<=N; ++i)
    {
        Adj[i]=-1;
    }
}

void Add_Edge(int u,int v,char type)
{
    E[Size].mV=v;
    E[Size].mNext=Adj[u];
    E[Size].mType=type;
    Adj[u]=Size++;
}

void BFS(int start)
{
    int i,Head,Tail,flag;
    Head=0;
    Tail=1;
    Queue[Head].mIndex=start;
    Queue[Head].mValue=0;
    Visited[start]=1;
    while(Head<Tail)
    {
        for(flag=0,i=Adj[Queue[Head].mIndex]; ~i; i=E[i].mNext)
        {
            if(!Visited[E[i].mV])
            {
                Queue[Tail].mIndex=E[i].mV;
                Queue[Tail].mValue=Queue[Head].mValue;
                if(E[i].mType==2)
                {
                    Updated[Queue[Head].mValue]=1;
                    Queue[Tail].mValue=E[i].mV;
                }
                ++Tail;
                Visited[E[i].mV]=1;
                flag=1;
            }
        }
        if(flag==0&&Queue[Head].mValue!=0&&Stored[Queue[Head].mValue]==0)
        {
            Stored[Queue[Head].mValue]=1;
            Ans[AnsCnt++]=Queue[Head].mValue;
        }
        ++Head;
    }
}

int main()
{
    int N,i,u,v,type;
    scanf("%d",&N);
    Init(N);
    for(i=0; i<N-1; ++i)
    {
        scanf("%d %d %d",&u,&v,&type);
        Add_Edge(u,v,type);
        Add_Edge(v,u,type);
    }
    BFS(1);
    for(i=0; i<AnsCnt; ++i)
    {
        if(Updated[Ans[i]])
        {
            Ans[i]=Ans[AnsCnt-1];
            --i;
            --AnsCnt;
        }
    }
    printf("%d\n",AnsCnt);
    for(i=0; i<AnsCnt; ++i)
    {
        printf("%d ",Ans[i]);
    }
    return 0;
}
