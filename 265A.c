#include <stdio.h>

int main()
{
    int i,j;
    char Str[51],T[51];
    scanf("%s %s",Str,T);
    for(i=j=0; Str[i]!='\0'&&T[j]!='\0'; ++j)
    {
        if(Str[i]==T[j])
        {
            ++i;
        }
    }
    printf("%d\n",i+1);
    return 0;
}
