#include <stdio.h>

char FlagA[10];
char FlagB[10];

int main()
{
    int n, m, num, a, b;
    a = b = 9;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        FlagA[num] = 1;
        if(a > num) {
            a = num;
        }
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &num);
        FlagB[num] = 1;
        if(b > num) {
            b = num;
        }
    }
    for(int i = 1; i <= 9; ++i) {
        if(FlagA[i] && FlagB[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    if(a < b) {
        printf("%d%d\n", a, b);
    } else {
        printf("%d%d\n", b, a);
    }
    return 0;
}
