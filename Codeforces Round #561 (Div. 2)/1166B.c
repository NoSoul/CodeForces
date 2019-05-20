#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, m;
    char table[6] = {"aeiou"};
    scanf("%d", &n);
    m = sqrt(n);
    for(int i = 5; i <= m; ++i) {
        if(n % i == 0) {
            int j = n / i;
            if(j >= 5) {
                for(int l = 0; l < j; ++l) {
                    for(int k = 0; k < i; ++k) {
                        printf("%c", table[(k + l) % 5]);
                    }
                }
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}
