#include <stdio.h>

int main()
{
    int n;
    int A[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n; ++i) {
        int k = i;
        for(int j = i + 1; j < n; ++j) {
            if(A[k] > A[j]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = A[i];
            A[i] = A[k];
            A[k] = temp;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i += 2) {
        ans += A[i + 1] - A[i];
    }
    printf("%d\n", ans);
    return 0;
}
