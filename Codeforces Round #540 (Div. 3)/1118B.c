#include <stdio.h>

int A[200001];
long long sumEven[200001];
long long sumOdd[200001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        if(i < 2) {
            sumEven[i] = A[i];
            sumOdd[i] = A[i];
        } else {
            sumOdd[i] = sumOdd[i - 2] + A[i];
            sumEven[i] = sumEven[i - 2] + A[i];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        long long even = 0;
        long long odd = 0;
        if(i & 1) {
            if(n & 1) {
                if(i - 1 >= 0) {
                    even += sumEven[i - 1];
                }
                even += sumEven[n - 2] - sumEven[i];
                if(i - 2 >= 0) {
                    odd += sumOdd[i - 2];
                }
                odd += sumOdd[n - 1];
                if(i - 1 >= 0) {
                    odd -= sumOdd[i - 1];
                }
            } else {
                if(i - 1 >= 0) {
                    even += sumEven[i - 1];
                }
                even += sumEven[n - 1] - sumEven[i];
                if(i - 2 >= 0) {
                    odd += sumOdd[i - 2];
                }
                odd += sumOdd[n - 2];
                if(i - 1 >= 0) {
                    odd -= sumOdd[i - 1];
                }
            }
        } else {
            if(n & 1) {
                if(i - 2 >= 0) {
                    even += sumEven[i - 2];
                }
                even += sumEven[n - 2];
                if(i - 1 >= 0) {
                    even -= sumEven[i - 1];
                }
                if(i - 1 >= 0) {
                    odd += sumOdd[i - 1];
                }
                odd += sumOdd[n - 1] - sumOdd[i];
            } else {
                if(i - 2 >= 0) {
                    even += sumEven[i - 2];
                }
                even += sumEven[n - 1];
                if(i - 1 >= 0) {
                    even -= sumEven[i - 1];
                }
                if(i - 1 >= 0) {
                    odd += sumOdd[i - 1];
                }
                odd += sumOdd[n - 2] - sumOdd[i];
            }
        }
        ans += even == odd;
    }
    printf("%d\n", ans);
    return 0;
}
