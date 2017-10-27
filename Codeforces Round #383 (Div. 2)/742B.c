#include <stdio.h>

int A[100001];

int main()
{
    int n, x, num;
    long long Ans = 0;
    scanf("%d %d", &n, &x);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        ++A[num];
    }
    for(int i = 1; i < 100001; ++i) {
        if(A[i]) {
            int need = x ^ i;
            if(need < 100001) {
                if(i != need) {
                    Ans += (long long)A[i] * A[need];
                } else {
                    Ans += (long long)A[i] * (A[need] - 1) / 2;
                }
                A[need] = 0;
            }
        }
    }
    printf("%I64d\n", Ans);
    return 0;
}
