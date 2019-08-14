#include <stdio.h>

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    puts(m >= n && k >= n ? "Yes" : "No");
    return 0;
}
