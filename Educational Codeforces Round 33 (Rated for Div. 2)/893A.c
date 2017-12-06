#include <stdio.h>

char flag[3];

int main()
{
    int n, a;
    scanf("%d", &n);
    flag[0] = flag[1] = 1;
    while(n--) {
        scanf("%d", &a);
        --a;
        if(!flag[a]) {
            puts("NO");
            return 0;
        }
        for(int i = 0; i < 3; ++i) {
            flag[i] ^= 1;
        }
        flag[a] = 1;
    }
    puts("YES");
    return 0;
}
