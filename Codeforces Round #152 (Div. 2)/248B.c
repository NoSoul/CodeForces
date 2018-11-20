#include <stdio.h>

int A[40000];

int main()
{
    int N, i, j, sum;
    scanf("%d", &N);
    if(N < 3) {
        printf("-1\n");
        return 0;
    }
    if(N == 3) {
        printf("210\n");
        return 0;
    }
    N -= 3;
    i = 0;
    while(N > 0) {
        if(N > 3) {
            A[i++] = 0;
        } else if(N == 3) {
            A[i++] = 100;
        } else if(N == 1) {
            A[i++] = 1;
        } else {
            A[i++] = 10;
        }
        N -= 3;
    }
    for(sum = 0, j = i - 1; j >= 0; --j) {
        sum = sum * 1000 + A[j];
        sum %= 210;
        if(j == i - 1) {
            printf("%d", A[j]);
        } else {
            printf("000");
        }
    }
    for(i = 0; i < 211; ++i) {
        if((sum * 1000 + i) % 210 == 0) {
            break;
        }
    }
    printf("%03d\n", i);
    return 0;
}
