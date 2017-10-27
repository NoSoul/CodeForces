#include <stdio.h>

int main()
{
    int n, numOfTwo;
    scanf("%d", &n);
    numOfTwo = n / 2;
    printf("%d\n", numOfTwo);
    if(n & 1) {
        --numOfTwo;
        printf("3 ");
    }
    while(numOfTwo--) {
        printf("2 ");
    }
    puts("");
    return 0;
}
