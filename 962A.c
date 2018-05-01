#include <stdio.h>

int A[200001];

int main()
{
    int n, sum = 0, origin;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    origin = sum;
    for(int i = 0; i < n; ++i) {
        sum -= A[i];
        if((long long)2 * sum <= origin) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}
