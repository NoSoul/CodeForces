#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N == 1 || N == 2) {
        puts("-1");
        return 0;
    }
    printf("2 3 ");
    N -= 2;
    while(N--) {
        printf("1 ");
    }
    return 0;
}
