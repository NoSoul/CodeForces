#include <stdio.h>

int main()
{
    char Str[101];
    int A[4]= {0};
    int i;
    scanf("%s",Str);
    ++A[Str[0]-'0'];
    for(i=1; Str[i]!='\0'; ++i)
    {
        ++i;
        ++A[Str[i]-'0'];
    }
    if(A[1]>0)
    {
        printf("1");
        --A[1];
    }
    else if(A[2]>0)
    {
        printf("2");
        --A[2];
    }
    else if(A[3]>0)
    {
        printf("3");
        --A[3];
    }
    for(i=0; i<A[1]; ++i)
    {
        printf("+1");
    }
    for(i=0; i<A[2]; ++i)
    {
        printf("+2");
    }
    for(i=0; i<A[3]; ++i)
    {
        printf("+3");
    }
    return 0;
}
