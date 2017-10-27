#include <stdio.h>

char Val[26];

int main()
{
    int N, M, i, j;
    char Str[200001], x[2], y[2];
    for(i = 0; i < 26; ++i) {
        Val[i] = 'a' + i;
    }
    scanf("%d %d %s", &N, &M, Str);
    for(i = 0; i < M; ++i) {
        scanf("%s %s", x, y);
        for(j = 0; j < 26; ++j) {
            if(Val[j] == x[0]) {
                Val[j] = y[0];
            } else if(Val[j] == y[0]) {
                Val[j] = x[0];
            }
        }
    }
    for(i = 0; i < N; ++i) {
        putchar(Val[Str[i] - 'a']);
    }
    putchar('\n');
    return 0;
}
