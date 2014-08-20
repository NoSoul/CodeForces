#include <stdio.h>

int main()
{
    int N,Num;
    int a,b;
    a=b=0;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&Num);
        if(Num==25)
        {
            ++a;
        }
        else if(Num==50)
        {
            ++b;
            --a;
        }
        else
        {
            if(b>0)
            {
                --b;
                --a;
            }
            else
            {
                a-=3;
            }
        }
        if(a<0||b<0)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
