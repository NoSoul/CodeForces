#include <stdio.h>

int Fun(int num)
{
    int ret = num;
    while(num) {
        ret += num % 10;
        num /= 10;
    }
    return ret;
}

int main()
{
    int n, Cnt = 0;
    int Ans[101];
    scanf("%d", &n);
    for(int i = n - 100; i <= n; ++i) {
        if(i > 0) {
            if(Fun(i) == n) {
                Ans[Cnt++] = i;
            }
        }
    }
    printf("%d\n", Cnt);
    for(int i = 0; i < Cnt; ++i) {
        printf("%d\n", Ans[i]);
    }
    return 0;
}
