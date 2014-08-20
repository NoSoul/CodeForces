#include <stdio.h>

int main()
{
    int X,T,i,A,B,da,db,Num;
    scanf("%d %d %d %d %d %d",&X,&T,&A,&B,&da,&db);
    if(X==0)
    {
        puts("YES");
        return 0;
    }
    for(i=0; i<T; ++i)
    {
        if((X==A-da*i)||(X==B-db*i))
        {
            break;
        }
    }
    if(i<T)
    {
        puts("YES");
        return 0;
    }
    for(i=0; i<T; ++i)
    {
        Num=A-da*i;
        if((B+Num-X)%db==0&&(B+Num-X)>=0&&(B+Num-X)<=(T-1)*db)
        {
            break;
        }
    }
    puts(i<T?"YES":"NO");
    return 0;
}
