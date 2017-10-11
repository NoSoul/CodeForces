#include <stdio.h>

int main()
{
    int n;
    int A[100];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    if(A[0] % 2 == 0 || A[n - 1] % 2 == 0) {
        puts("No");
    } else {
        puts(n & 1 ? "Yes" : "No");
    }
    return 0;
}
