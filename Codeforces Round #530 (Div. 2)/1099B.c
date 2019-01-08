#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1 + n;
    for(int i = sqrt(n); i > 0; --i) {
        if(ans > i + n / i + (n / i * i != n)) {
            ans = i + n / i + (n / i * i != n);
        }
    }
    printf("%d\n", ans);
    return 0;
}
