#include <stdio.h>

int main()
{
    int N,X,Y,Z,x,y,z,i;
    X=Y=Z=0;
    scanf("%d",&N);
    for(i=0; i<N; ++i)
    {
        scanf("%d %d %d",&x,&y,&z);
        X+=x;
        Y+=y;
        Z+=z;
    }
    puts((X==0&&Y==0&&Z==0)?"YES":"NO");
    return 0;
}
