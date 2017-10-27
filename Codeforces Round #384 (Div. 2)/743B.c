#include <stdio.h>

int main()
{
    int n, Ans;
    long long cur, k;
    scanf("%d %I64d", &n, &k);
    cur = 1;
    Ans = 1;
    for(int i = 0; i < n - 1; ++i) {
        cur = cur * 2 + 1;
        ++Ans;
    }
    while(1) {
        if(k == cur / 2 + 1) {
            printf("%d\n", Ans);
            break;
        } else if(k > cur / 2 + 1) {
            k -= cur / 2 + 1;
        }
        cur = (cur - 1) / 2;
        --Ans;
    }
    return 0;
}
