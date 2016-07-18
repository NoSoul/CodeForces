#include <stdio.h>

int main()
{
    int n, num, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        sum += num;
    }
    if(n == 1) {
        puts(sum == 1 ? "YES" : "NO");
        return 0;
    }
    puts(sum == n - 1 ? "YES" : "NO");
    return 0;
}
