#include <stdio.h>

int main()
{
    int n, S, ans = 0;
    scanf("%d %d", &n, &S);
    while(S) {
        ++ans;
        if(S >= n) {
            S -= n;
        } else {
            S = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
