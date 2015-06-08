#include <stdio.h>

char HashRow[50], HashCol[50];

int main()
{
    int N, M, i, j;
    int MinC, MaxC, MinR, MaxR;
    char Str[50][51];
    scanf("%d %d", &N, &M);
    for(i = 0; i < N; ++i) {
        scanf("%s", Str[i]);
        for(j = 0; j < M; ++j) {
            if(Str[i][j] == '*') {
                HashRow[i] = 1;
                HashCol[j] = 1;
            }
        }
    }
    for(i = 0; i < N; ++i) {
        if(HashRow[i]) {
            MinR = i;
            break;
        }
    }
    for(i = N - 1; i >= 0; --i) {
        if(HashRow[i]) {
            MaxR = i;
            break;
        }
    }
    for(i = 0; i < M; ++i) {
        if(HashCol[i]) {
            MinC = i;
            break;
        }
    }
    for(i = M - 1; i >= 0; --i) {
        if(HashCol[i]) {
            MaxC = i;
            break;
        }
    }
    for(i = MinR; i <= MaxR; ++i) {
        for(j = MinC; j <= MaxC; ++j) {
            printf("%c", Str[i][j]);
        }
        puts("");
    }
    return 0;
}
