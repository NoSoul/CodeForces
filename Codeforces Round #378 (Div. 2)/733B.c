#include <stdio.h>
#include <stdlib.h>

int L[100000];
int R[100000];
int SumL, SumR;

int main()
{
    int N, maxAns = 0, maxIdx = -1;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &L[i], &R[i]);
        SumL += L[i];
        SumR += R[i];
    }
    maxAns = abs(SumL - SumR);
    for(int i = 0; i < N; ++i) {
        int lprime = SumL - L[i] + R[i];
        int rprime = SumR - R[i] + L[i];
        if(abs(lprime - rprime) > maxAns) {
            maxAns = abs(lprime - rprime);
            maxIdx = i;
        }
    }
    printf("%d\n", maxIdx + 1);
    return 0;
}
