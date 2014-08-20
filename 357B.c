#include <stdio.h>

int Hash[100001];

int main()
{
    int N,M,x,y,z,i;
    scanf("%d %d",&N,&M);
    while(M--)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(Hash[x]==0&&Hash[y]==0&&Hash[z]==0)
        {
            Hash[x]=1;
            Hash[y]=2;
            Hash[z]=3;
        }
        if(Hash[x]!=0&&Hash[y]==0&&Hash[z]==0)
        {
            Hash[y]=Hash[x]==1?2:(Hash[x]==2?1:1);
            Hash[z]=Hash[x]==1?3:(Hash[x]==2?3:2);
        }
        if(Hash[x]==0&&Hash[y]!=0&&Hash[z]==0)
        {
            Hash[x]=Hash[y]==1?2:(Hash[y]==2?1:1);
            Hash[z]=Hash[y]==1?3:(Hash[y]==2?3:2);
        }
        if(Hash[x]==0&&Hash[y]==0&&Hash[z]!=0)
        {
            Hash[x]=Hash[z]==1?2:(Hash[z]==2?1:1);
            Hash[y]=Hash[z]==1?3:(Hash[z]==2?3:2);
        }
        if(Hash[x]==0&&Hash[y]!=0&&Hash[z]!=0)
        {
            Hash[x]=6-Hash[y]-Hash[z];
        }
        if(Hash[x]!=0&&Hash[y]==0&&Hash[z]!=0)
        {
            Hash[y]=6-Hash[x]-Hash[z];
        }
        if(Hash[x]!=0&&Hash[y]!=0&&Hash[z]==0)
        {
            Hash[z]=6-Hash[x]-Hash[y];
        }
    }
    for(i=1; i<=N; ++i)
    {
        printf("%d ",Hash[i]);
    }
    return 0;
}
