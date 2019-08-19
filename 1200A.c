#include <stdio.h>

int main()
{
    int n;
    char str[100001];
    char Flag[10] = {0};
    scanf("%d %s", &n, str);
    for(int i = 0; i < n; ++i) {
        if(str[i] == 'L') {
            for(int j = 0; j < 10; ++j) {
                if(Flag[j] == 0) {
                    Flag[j] = 1;
                    break;
                }
            }
        } else if(str[i] == 'R') {
            for(int j = 9; j >= 0; --j) {
                if(Flag[j] == 0) {
                    Flag[j] = 1;
                    break;
                }
            }
        } else {
            Flag[str[i] - '0'] = 0;
        }
    }
    for(int i = 0; i < 10; ++i) {
        putchar(Flag[i] ? '1' : '0');
    }
    return 0;
}
