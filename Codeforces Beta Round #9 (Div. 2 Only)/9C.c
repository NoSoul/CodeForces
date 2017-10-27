#include <stdio.h>

int main()
{
    int N, i, j;
    int A[513];
    char Str[11];
    for(i = 1; i <= (1 << 9); ++i) {
        j = 0;
        N = i;
        while(N) {
            Str[j++] = N & 1;
            N >>= 1;
        }
        A[i] = 0;
        for(--j; j >= 0; --j) {
            A[i] *= 10;
            A[i] += Str[j];
        }
    }
    scanf("%d", &N);
    for(i = 512; i >= 0; --i) {
        if(N >= A[i]) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
