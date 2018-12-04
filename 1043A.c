#include <stdio.h>

int main()
{
    int n, max = 0, sum = 0, a;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
        if(max < a) {
            max = a;
        }
    }
    while(sum * 2 >= max * n) {
        ++max;
    }
    printf("%d\n", max);
    return 0;
}
