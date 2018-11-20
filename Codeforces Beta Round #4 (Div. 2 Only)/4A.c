#include <stdio.h>

int main()
{
    int W, i;
    while(scanf("%d", &W) != EOF) {
        for(i = 2; i < W; i += 2) {
            if((W - i) % 2 == 0) {
                break;
            }
        }
        if(i < W) {
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}
