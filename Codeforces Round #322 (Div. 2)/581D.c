#include <stdio.h>
#include <math.h>

int main()
{
    int N, M, cur, i, j;
    int x[4], y[4];
    scanf("%d %d %d %d %d %d", &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]);
    N = x[1] * y[1] + x[2] * y[2] + x[3] * y[3];
    M = sqrt(N);
    if(M * M != N) {
        puts("-1");
        return 0;
    }
    for(cur = 1; cur < 4; ++cur) {
        if(x[cur] == M || y[cur] == M) {
            int A[4];
            int B = x[cur] < y[cur] ? x[cur] : y[cur];
            int C = M - B;
            char outChA, outChB, outChC;
            if(cur == 1) {
                A[0] = x[2];
                A[1] = y[2];
                A[2] = x[3];
                A[3] = y[3];
                outChA = 'A';
                outChB = 'B';
                outChC = 'C';
            }
            if(cur == 2) {
                A[0] = x[1];
                A[1] = y[1];
                A[2] = x[3];
                A[3] = y[3];
                outChA = 'B';
                outChB = 'A';
                outChC = 'C';
            }
            if(cur == 3) {
                A[0] = x[1];
                A[1] = y[1];
                A[2] = x[2];
                A[3] = y[2];
                outChA = 'C';
                outChB = 'A';
                outChC = 'B';
            }
            for(i = 0; i < 2; ++i) {
                for(j = 2; j < 4; ++j) {
                    if(A[i] == A[j]) {
                        int k, l;
                        if(A[i] == C && A[i ^ 1] + A[j ^ 1] == M) {
                            printf("%d\n", M);
                            for(k = 0; k < B; ++k) {
                                for(l = 0; l < M; ++l) {
                                    putchar(outChA);
                                }
                                putchar('\n');
                            }
                            for(k = 0; k < C; ++k) {
                                for(l = 0; l < A[i ^ 1]; ++l) {
                                    putchar(outChB);
                                }
                                for(l = 0; l < A[j ^ 1]; ++l) {
                                    putchar(outChC);
                                }
                                putchar('\n');
                            }
                            return 0;
                        }
                        if(A[i] == M && A[i ^ 1] + A[j ^ 1] == C) {
                            printf("%d\n", M);
                            for(k = 0; k < B; ++k) {
                                for(l = 0; l < M; ++l) {
                                    putchar(outChA);
                                }
                                putchar('\n');
                            }
                            for(k = 0; k < A[i ^ 1]; ++k) {
                                for(l = 0; l < M; ++l) {
                                    putchar(outChB);
                                }
                                putchar('\n');
                            }
                            for(k = 0; k < A[j ^ 1]; ++k) {
                                for(l = 0; l < M; ++l) {
                                    putchar(outChC);
                                }
                                putchar('\n');
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    puts("-1");
    return 0;
}
