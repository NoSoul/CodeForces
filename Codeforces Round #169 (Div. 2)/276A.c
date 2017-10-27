#include <stdio.h>

int main()
{
    int N, K, Max, i, f, t, Now;
    scanf("%d %d", &N, &K);
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &f, &t);
        Now = t > K ? f - t + K : f;
        if(i == 0) {
            Max = Now;
        }
        Max = (Max < Now) ? Now : Max;
    }
    printf("%d\n", Max);
    return 0;
}