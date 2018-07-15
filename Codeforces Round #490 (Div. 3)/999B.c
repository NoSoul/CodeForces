#include <stdio.h>

int main()
{
    int n;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = n; i >= 1; --i) {
        if(n % i == 0) {
            int d = n / i;
            for(int i = 0, j = d - 1; i < j; ++i, --j) {
                char c = str[i];
                str[i] = str[j];
                str[j] = c;
            }
        }
    }
    puts(str);
    return 0;
}
