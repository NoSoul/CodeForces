#include <stdio.h>

int main()
{
    int n, min = 0x7fffffff;
    int A[100000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        if(min > A[i]) {
            min = A[i];
        }
    }
    for(int i = 0; i < n; ++i) {
        if(A[i] % min) {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n", min);
    return 0;
}
