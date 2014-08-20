#include <stdio.h>

int A[10];
char Str[81],Src[11];


int main()
{
    int i,j,s;
    scanf("%s",Str);
    for(i=0; i<10; ++i)
    {
        scanf("%s",Src);
        for(s=j=0; Src[j]!='\0'; ++j)
        {
            s*=2;
            s+=Src[j]-'0';
        }
        A[i]=s;
    }
    for(i=0; i<80; i+=10)
    {
        for(s=0,j=i; j<i+10; ++j)
        {
            s*=2;
            s+=Str[j]-'0';
        }
        for(j=0; j<10; ++j)
        {
            if(s==A[j])
            {
                printf("%d",j);
                break;
            }
        }
    }
    return 0;
}
