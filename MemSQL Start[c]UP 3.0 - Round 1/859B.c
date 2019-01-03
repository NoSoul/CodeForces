#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a = sqrt(n), b;
    if(n % a) {
        b = n / a + 1;
    } else {
        b = n / a;
    }
    printf("%d\n", 2 * (a + b));
    return 0;
}
