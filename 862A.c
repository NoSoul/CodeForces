#include <stdio.h>

char Flag[101];

int main()
{
    int n, x, a, Ans;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Flag[a];
    }
    Ans = Flag[x];
    for(int i = 0; i < x; ++i) {
        if(!Flag[i]) {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
