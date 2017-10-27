#include <stdio.h>

int main()
{
    int N, A, B, Now = 0, Max = 0;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d", &A, &B);
        Now = Now < A ? 0 : Now - A;
        Now += B;
        if(Max < Now) {
            Max = Now;
        }
    }
    printf("%d\n", Max);
    return 0;
}
