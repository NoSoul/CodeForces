#include <stdio.h>

int main()
{
    int n, a;
    scanf("%d", &n);
    int sum = 0, min = 200, oddCnt = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
        if(a & 1) {
            ++oddCnt;
            if(min > a) {
                min = a;
            }
        }
    }
    if(oddCnt == 0) {
        puts("0");
    } else {
        if(oddCnt & 1) {
            printf("%d\n", sum);
        } else {
            printf("%d\n", sum - min);
        }
    }
    return 0;
}
