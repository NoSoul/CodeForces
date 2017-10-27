#include <stdio.h>
#include <string.h>
#define MAXL    1000
int GetSum(char *str)
{
    int i, sum = 0;
    for(i = 0; str[i] != '\0'; ++i) {
        sum += str[i] - '0';
    }
    return sum;
}

int main()
{
    int N, i, j, Num, M;
    char A[300][MAXL];
    scanf("%d", &N);
    memset(A, '0', sizeof(A));
    for(i = 0; i < N; ++i) {
        A[i][MAXL - 1] = '\0';
        scanf("%d", &Num);
LOOP:
        M = GetSum(A[i]);
        if(M < Num) {
            Num -= M;
            j = 0;
            while(Num) {
                int cur = '9' - A[i][j];
                if(Num > cur) {
                    A[i][j] = '9';
                    Num -= cur;
                } else {
                    A[i][j] += Num;
                    break;
                }
                ++j;
            }
        } else if(M > Num) {
            int k;
            for(k = 1; k < MAXL; ++k) {
                A[i][k - 1] = '0';
                j = k;
                while(A[i][j] == '9') {
                    A[i][j] = '0';
                    ++j;
                }
                ++A[i][j];
                if(GetSum(A[i]) <= Num) {
                    break;
                }
            }
            goto LOOP;
        }
        if(i != N - 1) {
            memcpy(A[i + 1], A[i], sizeof(char) * MAXL);
            j = 0;
            while(A[i + 1][j] == '9') {
                A[i + 1][j] = '0';
                ++j;
            }
            ++A[i + 1][j];
        }
    }
    for(i = 0; i < N; ++i) {
        for(j = MAXL - 2; j >= 0; --j) {
            if(A[i][j] != '0') {
                break;
            }
        }
        for(; j >= 0; --j) {
            printf("%c", A[i][j]);
        }
        puts("");
    }
    return 0;
}
