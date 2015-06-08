#include <stdio.h>

void Show(int n)
{
    int i;
    if(n >= 5) {
        printf("-O|");
        n -= 5;
    } else {
        printf("O-|");
    }
    for(i = 0; i < n; ++i) {
        printf("O");
    }
    printf("-");
    for(i = 0; i < 4 - n; ++i) {
        printf("O");
    }
    printf("\n");
}

void Fun(int n)
{
    Show(n % 10);
    n /= 10;
    if(n == 0) {
        return;
    }
    Fun(n);
}

int main()
{
    int N;
    scanf("%d", &N);
    Fun(N);
    return 0;
}
