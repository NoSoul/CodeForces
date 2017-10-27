#include <stdio.h>

int A[5], B[5];

void Update(int *array, int num)
{
    int mod = num % 5;
    for(int i = 0; i < 5; ++i) {
        array[i] = num / 5;
        array[i] += mod >= (i + 1);
    }
}

int main()
{
    int n, m;
    long long ans = 0;
    scanf("%d %d", &n, &m);
    Update(A, n);
    Update(B, m);
    ans += (long long)A[4] * B[4];
    for(int i = 0; i < 4; ++i) {
        ans += (long long)A[i] * B[3 - i];
    }
    printf("%I64d\n", ans);
    return 0;
}
