#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        char str[101];
        scanf("%d %s", &n, str);
        char flag = 0;
        for(int i = 0, j = n - 1; i < j; ++i, --j) {
            int nextI = ((str[i] - 'a') + 1) % 26;
            int preI = ((str[i] - 'a') - 1) % 26;
            int nextJ = ((str[j] - 'a') + 1) % 26;
            int preJ = ((str[j] - 'a') - 1) % 26;
            if(str[i] == 'a') {
                preI = nextI;
            } else if(str[i] == 'z') {
                nextI = preI;
            }
            if(str[j] == 'a') {
                preJ = nextJ;
            } else if(str[j] == 'z') {
                nextJ = preJ;
            }
            if(!(nextI == nextJ || nextI == preJ || preI == nextJ || preI == preJ)) {
                flag = 1;
                break;
            }
        }
        puts(flag ? "NO" : "YES");
    }
    return 0;
}
