#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int max = c;
    int sum = a + b + c;
    if(max < a) {
        max = a;
    }
    if(max < b) {
        max = b;
    }
    sum -= max;
    if(max >= sum) {
        printf("%d\n", max + 1 - sum);
    } else {
        printf("0\n");
    }
    return 0;
}
