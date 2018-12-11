#include <stdio.h>

int main()
{
    int n;
    char str[1001];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n; ++i) {
        if(str[i] == '1') {
            if((i - 1 >= 0 && str[i - 1] == '1') || (i + 1 < n && str[i + 1] == '1')) {
                puts("No");
                return 0;
            }
        } else {
            if((i - 1 < 0 || str[i - 1] == '0') && (i + 1 >= n || str[i + 1] == '0')) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    return 0;
}
