#include <stdio.h>
#include <stdlib.h>

char Str[8][3]= {"L\0","R\0","U\0","D\0","LU\0","LD\0","RU\0","RD\0"};
char Step[8][2]= {{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,-1},{-1,1},{1,1}};
char Ans[10];

typedef struct
{
    int x,y;
} Point;
Point S,E;

Point SetPoint()
{
    Point temp;
    char Str[2];
    scanf("%s",Str);
    temp.x='8'-Str[1];
    temp.y=Str[0]-97;
    return temp;
}

int Distance(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

void AStar(Point s,Point e)
{
    Point now=s,temp;
    int D[8],Min,id,i,cnt=0;
    while(1)
    {
        if(now.x==e.x&&now.y==e.y)
        {
            break;
        }
        for(i=0; i<8; ++i)
        {
            temp.x=now.x+Step[i][0];
            temp.y=now.y+Step[i][1];
            if(temp.x<0||temp.x>7||temp.y<0||temp.y>7)
            {
                D[i]=0x7fffffff;
            }
            else
            {
                D[i]=Distance(temp,e);
            }
        }
        for(Min=D[id=0],i=1; i<8; ++i)
        {
            if(D[i]<Min)
            {
                Min=D[i];
                id=i;
            }
        }
        now.x+=Step[id][0];
        now.y+=Step[id][1];
        Ans[cnt++]=id;
    }
    printf("%d\n",cnt);
    for(i=0; i<cnt; ++i)
    {
        printf("%s\n",Str[Ans[i]]);
    }
    return;
}

int main()
{
    S=SetPoint();
    E=SetPoint();
    AStar(S,E);
    return 0;
}

