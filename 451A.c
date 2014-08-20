#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    if(N < M)
    {
        M = N;
    }
    else
    {
        N = M;
    }
    puts(N&1?"Akshat":"Malvika");
    return 0;
}
