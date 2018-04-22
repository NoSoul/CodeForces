#include <stdio.h>

int Func(int num)
{
    int ret = 0;
    while(num) {
        ret += num % 10;
        num /= 10;
    }
    return ret == 10;
}

int main()
{
    int k, cur = 0, num = 19;
    scanf("%d", &k);
    while(1) {
        if(Func(num)) {
            if(++cur == k) {
                printf("%d\n", num);
                break;
            }
        }
        num += 9;
    }
    return 0;
}
