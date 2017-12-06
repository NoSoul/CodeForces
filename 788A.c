#include <stdio.h>
#include <stdlib.h>

int A[100000];

int main()
{
    int n;
    long long sum, max = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    sum = 0;
    for(int i = 0; i < n - 1; ++i) {
        int num = abs(A[i] - A[i + 1]);
        if(i & 1) {
            num = -num;
        }
        if(sum + num > max) {
            max = sum + num;
        }
        if(sum + num < 0) {
            sum = 0;
        } else {
            sum += num;
        }
    }
    sum = 0;
    for(int i = 1; i < n - 1; ++i) {
        int num = abs(A[i] - A[i + 1]);
        if(!(i & 1)) {
            num = -num;
        }
        if(sum + num > max) {
            max = sum + num;
        }
        if(sum + num < 0) {
            sum = 0;
        } else {
            sum += num;
        }
    }
    printf("%I64d\n", max);
    return 0;
}
