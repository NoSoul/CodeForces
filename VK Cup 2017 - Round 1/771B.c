#include <stdio.h>
#include <string.h>

int main()
{
    int n, k;
    unsigned char str[4], ans[51];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        ans[i] = i + 1;
    }
    for(int i = 0; i < n - k + 1; ++i) {
        scanf("%s", str);
        if(str[0] == 'N') {
            ans[i + k - 1] = ans[i];
        }
    }
    for(int i = 0; i < n; ++i) {
        if(ans[i] < 27) {
            printf("%c ", 'A' + ans[i] - 1);
        } else {
            printf("A%c ", 'a' + ans[i] - 27);
        }
    }
    puts("");
    return 0;
}
