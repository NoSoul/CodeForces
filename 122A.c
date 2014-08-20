#include <stdio.h>

int A[14]= {4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main()
{
    int N,i,j;
    scanf("%d",&N);
    for(j=i=0; A[i]<=N&&i<14; ++i)
    {
        if(N%A[i]==0)
        {
            j=1;
            break;
        }
    }
    puts(j?"YES":"NO");
    return 0;
}
