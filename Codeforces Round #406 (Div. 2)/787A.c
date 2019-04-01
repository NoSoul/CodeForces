#include <stdio.h>

char flag[100];

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int cnt = 0;
    while(1) {
        if((d + cnt * c - b) % a == 0 && d + cnt * c - b >= 0) {
            printf("%d\n", d + cnt * c);
            return 0;
        }
        if(d + cnt * c - b >= 0) {
            if(flag[(d + cnt * c - b) % a] == 1) {
                puts("-1");
                return 0;
            }
            flag[(d + cnt * c - b) % a] = 1;
        }
        ++cnt;
    }
    return 0;
}
