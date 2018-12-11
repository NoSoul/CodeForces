#include <stdio.h>

int main()
{
    int n, sum = 0;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        sum += str[i] - '0';
    }
    for(int seg = 2; seg <= n; ++seg) {
        if(sum % seg == 0) {
            int cur = 0;
            char pass = 1;
            for(int i = 0; str[i]; ++i) {
                if(cur < sum / seg) {
                    cur += str[i] - '0';
                } else if(cur == sum / seg) {
                    cur = str[i] - '0';
                } else {
                    pass = 0;
                    break;
                }
            }
            if(pass && cur <= sum / seg) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
