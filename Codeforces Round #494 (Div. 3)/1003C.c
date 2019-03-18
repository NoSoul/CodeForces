#include <stdio.h>

int A[5001];

int main()
{
    int n, k, a;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        A[i] = A[i - 1] + a;
    }
    int max = 1;
    int maxLen = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + k - 1; j <= n; ++j) {
            if((long long)max * (j - i + 1) < (long long)maxLen * (A[j] - A[i - 1])) {
                max = A[j] - A[i - 1];
                maxLen = j - i + 1;
            }
        }
    }
    printf("%f\n", 1.0 * max / maxLen);
    return 0;
}
