#include <stdio.h>

int main()
{
    int Cnt=1;
    int N;
    char Str[3],Pre;
    scanf("%d %s",&N,Str);
    Pre=Str[1];
    while(--N)
    {
        scanf("%s",Str);
        if(Str[0]==Pre)
        {
            ++Cnt;
            Pre=Str[1];
        }
    }
    printf("%d\n",Cnt);
    return 0;
}
