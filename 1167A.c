#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        char str[101];
        scanf("%d %s", &n, str);
        char check = 0;
        for(int i = 0; i + 10 <= n - 1; ++i) {
            if(str[i] == '8') {
                check = 1;
                break;
            }
        }
        puts(check ? "YES" : "NO");
    }
    return 0;
}
