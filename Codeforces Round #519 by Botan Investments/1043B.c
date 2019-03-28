#include <stdio.h>

int A[1001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = n; i > 0; --i) {
        A[i] -= A[i - 1];
    }
    int ans[1000];
    int size = 0;
    for(int i = 1; i <= n; ++i) {
        int j = 1;
        for(j = 1; j <= n; ++j) {
            if(A[j] != A[(j % i) == 0 ? i : j % i]) {
                break;
            }
        }
        if(j > n) {
            ans[size++] = i;
        }
    }
    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
