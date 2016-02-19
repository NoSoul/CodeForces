#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N == 0) {
        puts("1");
    } else if(N == 1) {
        puts("5");
    } else {
        puts("25");
    }
    return 0;
}
