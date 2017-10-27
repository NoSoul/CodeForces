#include <stdio.h>
#include <math.h>

int main()
{
    long long N;
    scanf("%I64d", &N);
    N *= 2;
    for(long long i = sqrt(N) - 3; i < sqrt(N) + 3; ++i) {
        if(i * (i - 1) < N && N <= i * (i + 1)) {
            printf("%I64d\n", N / 2 - (i - 1)*i / 2);
            break;
        }
    }
    return 0;
}
