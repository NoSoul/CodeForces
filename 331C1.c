#include <stdio.h>

int Func(int n)
{
    int ret = 0;
    while(n) {
        if(ret < n % 10) {
            ret = n % 10;
        }
        n /= 10;
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n) {
        int val = Func(n);
        n -= val;
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
