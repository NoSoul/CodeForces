#include <stdio.h>

int main()
{
    int n;
    char A[200000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        cur = 0;
        while(i < n && A[i] == 1) {
            ++cur;
            ++i;
        }
        if(cur > ans) {
            ans = cur;
        }
    }
    if(A[n - 1] == 1) {
        int i = 0;
        while(i < n && A[i] == 1) {
            ++cur;
            ++i;
        }
        if(cur > ans) {
            ans = cur;
        }
    }
    printf("%d\n", ans);
    return 0;
}
