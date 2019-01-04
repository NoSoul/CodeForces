#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int A[100];
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(A[i] < A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    printf("%d\n", A[k - 1]);
    return 0;
}
