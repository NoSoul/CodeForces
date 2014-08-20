#include <stdio.h>

#define MAX 101

int main()
{
    int i,Cnt,Res;
    char Pre;
    char Stack[MAX];
    scanf("%s",Stack);
    for(Res=0,Pre=Stack[0],Cnt=i=1; Stack[i]!='\0'; ++i)
    {
        if(Stack[i]!=Pre)
        {
            Res+=(Cnt+4)/5;
            Cnt=1;
            Pre=Stack[i];
        }
        else
        {
            ++Cnt;
        }
    }
    if(Stack[i]!=Pre)
    {
        Res+=(Cnt+4)/5;
    }
    printf("%d\n",Res);
    return 0;
}
