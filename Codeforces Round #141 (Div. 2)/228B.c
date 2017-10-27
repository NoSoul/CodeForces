#include <stdio.h>

int main()
{
    int na, ma, nb, mb, i, j, x, y, Max, X, Y, Sum;
    char Str1[51][51], Str2[51][51];
    scanf("%d %d", &na, &ma);
    for(i = 0; i < na; ++i) {
        scanf("%s", Str1[i]);
    }
    scanf("%d %d", &nb, &mb);
    for(i = 0; i < nb; ++i) {
        scanf("%s", Str2[i]);
    }
    for(Max = 0, x = -na + 1; x < nb; ++x) {
        for(y = -ma + 1; y < mb; ++y) {
            for(Sum = i = 0; i < na; ++i) {
                for(j = 0; j < ma; ++j) {
                    if(i + x >= 0 && i + x < nb && j + y >= 0 && j + y < mb) {
                        Sum += (Str1[i][j] - '0') * (Str2[i + x][j + y] - '0');
                    }
                }
            }
            if(Sum > Max) {
                Max = Sum;
                X = x;
                Y = y;
            }
        }
    }
    printf("%d %d\n", X, Y);
    return 0;
}
