#include <stdio.h>

int main()
{
    int N,M,s,f,now,next,d,t,l,r,pret;
    int dis,i;
    scanf("%d %d %d %d",&N,&M,&s,&f);
    d=f>s?1:-1;
    now=s;
    next=s+d;
    pret=0;
    while(M--)
    {
        scanf("%d %d %d",&t,&l,&r);
        if(t-pret>1)
        {
            dis=f>now?f-now:now-f;
            if(dis<=(t-pret-1))
            {
                for(i=0; i<dis; ++i)
                {
                    putchar(f>s?'R':'L');
                }
                return 0;
            }
            else
            {
                for(i=0; i<t-pret-1; ++i)
                {
                    putchar(f>s?'R':'L');
                }
                now+=d*(t-pret-1);
                next=now+d;
            }
        }
        if((now<=r&&now>=l)||(next<=r&&next>=l))
        {
            printf("X");
        }
        else
        {
            putchar(f>s?'R':'L');
            now=next;
            next=now+d;
            if(now==f)
            {
                return 0;
            }
        }
        pret=t;
    }
    dis=f>now?f-now:now-f;
    for(i=0; i<dis; ++i)
    {
        putchar(f>s?'R':'L');
    }
    return 0;
}
