#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = sqrt(n); i >= 1; --i) {
        if(n % i == 0) {
            printf("%d %d\n", i, n / i);
            break;
        }
    }
    return 0;
}
