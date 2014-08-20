#include <stdio.h>

typedef long long LL_t;

char Str[1000001];
int A[200001];
int Size,Cnt;
LL_t Sum;

int main()
{
    int i;
    scanf("%s",Str);
    for(i=0; Str[i+4]!='\0'; ++i)
    {
        if(Str[i]=='h')
        {
            if(Str[i+1]=='e'&&Str[i+2]=='a'&&Str[i+3]=='v'&&Str[i+4]=='y')
            {
                i+=4;
                A[Size++]=1;
            }
        }
        if(Str[i]=='m')
        {
            if(Str[i+1]=='e'&&Str[i+2]=='t'&&Str[i+3]=='a'&&Str[i+4]=='l')
            {
                i+=4;
                A[Size++]=2;
            }
        }
    }
    Cnt=Sum=0;
    for(i=Size-1; i>=0; --i)
    {
        if(A[i]==2)
        {
            ++Cnt;
        }
        if(A[i]==1)
        {
            Sum+=(LL_t)Cnt;
        }
    }
    printf("%I64d\n",Sum);
    return 0;
}
