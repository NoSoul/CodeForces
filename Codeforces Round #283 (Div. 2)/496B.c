#include <stdio.h>

int main()
{
    int N, i, j, MinId;
    char Str[1001];
    scanf("%d %s", &N, Str);
    MinId = 0;
    for(i = 1; i < N; ++i) {
        int A = 10 - Str[MinId] + '0';
        int B = 10 - Str[i] + '0';
        for(j = 0; j < N; ++j) {
            if((Str[(j + i) % N] + B - '0') % 10 <
                    (Str[(j + MinId) % N] + A - '0') % 10) {
                MinId = i;
                break;
            }
            if((Str[(j + i) % N] + B - '0') % 10 >
                    (Str[(j + MinId) % N] + A - '0') % 10) {
                break;
            }
        }
    }
    int Dis = 10 - Str[MinId] + '0';
    for(j = 0; j < N; ++j) {
        printf("%c", (Str[(j + MinId) % N] + Dis - '0') % 10 + '0');
    }
    puts("");
    return 0;
}
