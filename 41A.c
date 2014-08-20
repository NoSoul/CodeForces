#include <stdio.h>
#include <string.h>

#define MAX 101

char Str1[MAX],Str2[MAX];

int main()
{
    int i,j,Len;
    scanf("%s %s",Str1,Str2);
    Len=strlen(Str1);
    if(Len!=strlen(Str2))
    {
        puts("NO");
        return 0;
    }
    for(i=0,j=Len-1; Str1[i]==Str2[j]&&i<Len; ++i,--j);
    puts(i==Len?"YES":"NO");
    return 0;
}
