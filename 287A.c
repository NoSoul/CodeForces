#include <stdio.h>

char Map[5][5];

int F(int i,int j)
{
    int Cnt=0;
    if(Map[i][j]=='#')
    {
        ++Cnt;
    }
    if(Map[i][j+1]=='#')
    {
        ++Cnt;
    }
    if(Map[i+1][j]=='#')
    {
        ++Cnt;
    }
    if(Map[i+1][j+1]=='#')
    {
        ++Cnt;
    }
    return Cnt==2?0:1;
}

int main()
{
    int i,j;
    for(i=0; i<4; ++i)
    {
        scanf("%s",Map[i]);
    }
    for(i=0; i<3; ++i)
    {
        for(j=0; j<3; ++j)
        {
            if(F(i,j))
            {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
