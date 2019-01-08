#include <stdio.h>

int main()
{
    int hh, mm, H, D, C, N;
    scanf("%d %d %d %d %d %d", &hh, &mm, &H, &D, &C, &N);
    if(hh >= 20) {
        int buns = (H + N - 1) / N;
        printf("%f\n", buns * C * 0.8);
    } else {
        float ans0 = (H + N - 1) / N * C;
        int minute = 60 - mm;
        ++hh;
        minute += (20 - hh) * 60;
        float ans1 = (H + minute * D + N - 1) / N * C * 0.8;
        printf("%f\n", ans0 < ans1 ? ans0 : ans1);
    }
    return 0;
}
