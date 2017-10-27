#include <stdio.h>

int main()
{
    int n, p, q, i, j, k;
    char Str[101];
    scanf("%d %d %d", &n, &p, &q);
    scanf("%s", Str);
    for(i = 0; i * p <= n; ++i) {
        for(j = 0; j * q <= n; ++j) {
            if(i * p + j * q == n) {
                printf("%d\n", i + j);
                int s = 0;
                while(i--) {
                    for(k = s; k < s + p; ++k) {
                        putchar(Str[k]);
                    }
                    putchar('\n');
                    s += p;
                }
                while(j--) {
                    for(k = s; k < s + q; ++k) {
                        putchar(Str[k]);
                    }
                    putchar('\n');
                    s += q;
                }
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
