#include <stdio.h>

int A[200001];

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        A[a] = i;
    }
    int min = n + 1;
    int ans = -1;
    for(int i = 0; i < 200001; ++i) {
        if(A[i] && min > A[i]) {
            min = A[i];
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
