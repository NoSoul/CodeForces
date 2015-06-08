#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N & 1) {
        puts("black");
    } else {
        puts("white\n1 2");
    }
    return 0;
}
