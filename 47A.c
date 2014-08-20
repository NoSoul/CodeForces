#include <stdio.h>

int main()
{
    int N,i;
    int A[33];
    scanf("%d",&N);
    for(i=1; i<33; ++i)
    {
        A[i]=i*(i+1)/2;
        if(N==A[i])
        {
            break;
        }
    }
    puts(i==33?"NO":"YES");
    return 0;
}
