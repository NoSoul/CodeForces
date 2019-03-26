#include <stdio.h>

char Flag[100001];

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 1;
    while(1) {
        a *= 10;
        if(a / b == c) {
            printf("%d\n", ans);
            break;
        }
        a %= b;
        if(Flag[a]) {
            puts("-1");
            break;
        }
        Flag[a] = 1;
        ++ans;
    }
    return 0;
}
