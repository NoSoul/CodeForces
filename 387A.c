#include <stdio.h>

typedef struct
{
    int h,m;
} Time_t;


int main()
{
    Time_t s,t;
    scanf("%02d:%02d",&s.h,&s.m);
    scanf("%02d:%02d",&t.h,&t.m);
    if(s.h<t.h||(s.h==t.h&&s.m<t.m))
    {
        s.h+=24;
    }
    if(s.m<t.m)
    {
        s.m+=60;
        --s.h;
    }
    printf("%02d:%02d\n",s.h-t.h,s.m-t.m);
    return 0;
}
