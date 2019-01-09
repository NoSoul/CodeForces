#include <stdio.h>
#include <math.h>

int main()
{
    int N, M, i, j, k;
    scanf("%d", &N);
    M = sqrt(N);
    for(i = 1; i <= M; ++i) {
        j = (N - i * (i + 1) / 2) * 2;
        if(j > 0) {
            k = sqrt(j);
            if(j == k * (k + 1)) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
