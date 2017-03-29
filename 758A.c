#include <stdio.h>

int main()
{
    int n, num, sum = 0, max = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        sum += num;
        if(max < num) {
            max = num;
        }
    }
    printf("%d\n", max * n - sum);
    return 0;
}
