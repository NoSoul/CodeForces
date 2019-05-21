#include <stdio.h>

char Flag[1000001];

int main()
{
    int n;
    char str[1000001];
    scanf("%d %s", &n, str);
    int loop = n - 11;
    int i = 0, j = 0;
    for(int k = 0; k < loop; ++k) {
        char find = 0;
        if(k & 1) {
            for(int l = j; l < n; ++l) {
                if(!Flag[l] && str[l] == '8') {
                    Flag[l] = 1;
                    j = l + 1;
                    find = 1;
                    break;
                }
            }
            if(!find) {
                j = n;
            }
        } else {
            for(int l = i; l < n; ++l) {
                if(!Flag[l] && str[l] != '8') {
                    Flag[l] = 1;
                    i = l + 1;
                    find = 1;
                    break;
                }
            }
            if(!find) {
                i = n;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        if(!Flag[i]) {
            puts(str[i] == '8' ? "YES" : "NO");
            break;
        }
    }
    return 0;
}
