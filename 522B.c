#include <stdio.h>

int main()
{
    int N, i, SumW, H;
    int W[200000];
    int MaxH[2], MaxIdx;
    scanf("%d", &N);
    SumW = MaxH[0] = MaxH[1] = 0;
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &W[i], &H);
        SumW += W[i];
        if(H > MaxH[0]) {
            MaxH[1] = MaxH[0];
            MaxH[0] = H;
            MaxIdx = i;
        } else if(H > MaxH[1]) {
            MaxH[1] = H;
        }
    }
    for(i = 0; i < N; ++i) {
        printf("%d ", (SumW - W[i]) * (i == MaxIdx ? MaxH[1] : MaxH[0]));
    }
    puts("");
    return 0;
}
