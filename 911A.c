#include <stdio.h>

int main()
{
    int n;
    int A[100001];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    int min = A[0];
    int pos = 0;
    for(int i = 1; i < n; ++i) {
        if(min > A[i]) {
            min = A[i];
            pos = i;
        }
    }
    int ans = n;
    for(int i = pos + 1; i < n; ++i) {
        if(A[i] == min) {
            if(ans > i - pos) {
                ans = i - pos;
            }
            pos = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
