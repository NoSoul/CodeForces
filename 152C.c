#include <stdio.h>

char Flag[100][26];

int main()
{
    int N, M, i, j, Ans = 1;
    char Str[101];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Str);
        for(j = 0; Str[j]; ++j) {
            Flag[j][Str[j] - 'A'] = 1;
        }
    }
    for(i = 0; i < M; ++i) {
        int cur = 0;
        for(j = 0; j < 26; ++j) {
            cur += Flag[i][j];
        }
        Ans = ((long long)Ans * cur) % 1000000007;
    }
    printf("%d\n", Ans);
    return 0;
}
