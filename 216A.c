#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A,B,C,Sum,i,D;
    scanf("%d %d %d",&A,&B,&C);
    D=B;
    if(D>A)
    {
        D=A;
    }
    for(Sum=i=0; i<D-1; ++i)
    {
        Sum+=C+i;
    }
    Sum<<=1;
    Sum+=(abs(B-A)+1)*(C+i);
    printf("%d\n",Sum);
    return 0;
}
