#include <stdio.h>

int main()
{
    int n;
    char str[200001];
    int f[10];
    scanf("%d %s", &n, str);
    for(int i = 1; i <= 9; ++i) {
        scanf("%d", &f[i]);
    }
    char exec = 0;
    for(int i = 0; i < n; ++i) {
        if(f[str[i] - '0'] > str[i] - '0') {
            str[i] = '0' + f[str[i] - '0'];
            exec = 1;
        } else if(f[str[i] - '0'] < str[i] - '0') {
            if(exec == 1) {
                break;
            }
        }
    }
    puts(str);
    return 0;
}
