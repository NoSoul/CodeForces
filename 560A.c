#include <stdio.h>

int main()
{
    int N, Num;
    char flag = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &Num);
        if(Num == 1) {
            flag = 1;
        }
    }
    puts(flag ? "-1" : "1");
    return 0;
}
