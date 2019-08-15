#include <stdio.h>

int Fun(int x)
{
    int sum = 0;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return !(sum & 3);
}

int main()
{
    int n;
    scanf("%d", &n);
    while(1) {
        if(Fun(n)) {
            printf("%d\n", n);
            break;
        }
        ++n;
    }
    return 0;
}
