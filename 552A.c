#include <stdio.h>

int Map[100][100];

int main()
{
    int N, i, j, x1, y1, x2, y2;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        --x1;
        --y1;
        --x2;
        --y2;
        for(i = x1; i <= x2; ++i) {
            for(j = y1; j <= y2; ++j) {
                ++Map[i][j];
            }
        }
    }
    int Sum = 0;
    for(i = 0; i < 100; ++i) {
        for(j = 0; j < 100; ++j) {
            Sum += Map[i][j];
        }
    }
    printf("%d\n", Sum);
    return 0;
}
