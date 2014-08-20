#include <stdio.h>
#include <stdlib.h>

int Odds(int a,int b,int c,int d)
{
    return (a&1)+(b&1)+(c&1)+(d&1);
}

void SolveRook(int r1,int c1,int r2,int c2)
{
    if(r1==r2&&c1==c2)
    {
        printf("0 ");
    }
    else if(r1==r2||c1==c2)
    {
        printf("1 ");
    }
    else
    {
        printf("2 ");
    }
}

void SolveBishop(int r1,int c1,int r2,int c2)
{
    if(r1==r2&&c1==c2)
    {
        printf("0 ");
    }
    else if(abs(r1-r2)==abs(c1-c2))
    {
        printf("1 ");
    }
    else if((Odds(r1,c1,r2,c2)&1)==0)
    {
        printf("2 ");
    }
    else
    {
        printf("0 ");
    }
}

void SolveKing(int r1,int c1,int r2,int c2)
{
    printf("%d ",abs(r1-r2)>=abs(c1-c2)?abs(r1-r2):abs(c1-c2));
}


int main()
{
    int R1,C1,R2,C2;
    scanf("%d %d %d %d",&R1,&C1,&R2,&C2);
    SolveRook(R1,C1,R2,C2);
    SolveBishop(R1,C1,R2,C2);
    SolveKing(R1,C1,R2,C2);
    return 0;
}
