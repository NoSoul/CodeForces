#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, num, sum = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        sum += num;
    }
    int ans = 0;
    while(1) {
        if(round((sum + ans * k) * 1.0 / (n + ans)) == k) {
            break;
        }
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
