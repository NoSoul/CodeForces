#include <stdio.h>

int main()
{
    int n, k;
    int A[100000];
    int Ans[100000];
    int size = 0, sum = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        sum += A[i];
    }
    if(sum % k) {
        puts("No");
    } else {
        sum /= k;
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            cur += A[i];
            if(cur == sum) {
                cur = 0;
                Ans[size++] = i;
            }
        }
        if(Ans[size - 1] == n - 1) {
            puts("Yes");
            for(int i = 0; i < size; ++i) {
                if(i == 0) {
                    printf("%d ", Ans[i] + 1);
                } else {
                    printf("%d ", Ans[i] - Ans[i - 1]);
                }
            }
        } else {
            puts("No");
        }
    }
    return 0;
}
