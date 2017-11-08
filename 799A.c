#include <stdio.h>

int main()
{
    int n, t, k, d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    int old = (n + (k - 1)) / k * t;
    int new = 0;
    while(n > 0) {
        ++new;
        if(new % t == 0) {
            n -= k;
        }
        if(new > d && (new - d) % t == 0) {
            n -= k;
        }
    }
    puts(new < old ? "YES" : "NO");
    return 0;
}
