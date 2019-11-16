#include <stdio.h>

int Fun(int num)
{
    int cnt[10] = {0};
    while(num) {
        ++cnt[num % 10];
        num /= 10;
    }
    for(int i = 0; i < 10; ++i) {
        if(cnt[i] > 1) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int l, r;
    scanf("%d %d", &l, &r);
    for(int i = l; i <= r; ++i) {
        if(Fun(i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
