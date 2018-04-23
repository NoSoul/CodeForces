#include <stdio.h>

int Flag[601];

int main()
{
    int n, a;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &a);
        Flag[a] = 1;
    }
    int ans = 0;
    for(int i = 1; i < 601; ++i) {
        ans += Flag[i];
    }
    printf("%d\n", ans);
    return 0;
}
