#include <stdio.h>

int Func(int num)
{
    for(int i = 0; i <= num / 3; ++i) {
        if((num - i * 3) % 7 == 0) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        puts(Func(x) ? "YES" : "NO");
    }
    return 0;
}
