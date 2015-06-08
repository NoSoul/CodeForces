#include <stdio.h>

int Fun(int x)
{
    int a, b, c, d;
    a = x / 1000;
    b = (x / 100) % 10;
    c = (x / 10) % 10;
    d = x % 10;
    return a != b && a != c && a != d && b != c && b != d && c != d;
}

int main()
{
    int N, i;
    scanf("%d", &N);
    for(i = N + 1; i < 9013; ++i) {
        if(Fun(i)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

