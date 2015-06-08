#include <stdio.h>

int main()
{
    int N, i, Ans, j, k, sum, flag;
    int A[20000];
    while(scanf("%d", &N) != EOF) {
        for(Ans = i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
            Ans += A[i];
        }
        for(i = 3; i <= N / 2; ++i) {
            if((N - i) % i == 0) {
                for(j = 0; j < (N - i) / i + 1; ++j) {
                    sum = flag = 0;
                    for(k = j; k % N != j || !flag; k += (N - i) / i + 1) {
                        flag = 1;
                        if(k >= N) {
                            k %= N;
                        }
                        sum += A[k];
                    }
                    if(Ans < sum) {
                        Ans = sum;
                    }
                }
            }
        }
        printf("%d\n", Ans);
    }
    return 0;
}
