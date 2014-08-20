#include <stdio.h>

int main()
{
    int N,k,l,c,d,p,nl,np,Min;
    scanf("%d %d %d %d %d %d %d %d",&N,&k,&l,&c,&d,&p,&nl,&np);
    Min=k*l/nl;
    Min=Min<c*d?Min:c*d;
    Min=Min<p/np?Min:p/np;
    printf("%d\n",Min/N);
    return 0;
}
