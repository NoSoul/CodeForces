#include <stdio.h>

char S[200001];
char T[200001];
char Visited[200001];
int Cnt[52];

int GetIdx(char c)
{
    if(c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return 26 + c - 'A';
}

int main()
{
    int i, A, B;
    scanf("%s %s", S, T);
    for(i = 0; T[i] != '\0'; ++i) {
        ++Cnt[GetIdx(T[i])];
    }
    for(A = i = 0; S[i] != '\0'; ++i) {
        int idx = GetIdx(S[i]);
        if(Cnt[idx]) {
            --Cnt[idx];
            ++A;
            Visited[i] = 1;
        }
    }
    for(B = i = 0; S[i] != '\0'; ++i) {
        if(!Visited[i]) {
            int idx = GetIdx(S[i]);
            if(Cnt[idx < 26 ? idx + 26 : idx - 26]) {
                --Cnt[idx < 26 ? idx + 26 : idx - 26];
                ++B;
            }
        }
    }
    printf("%d %d\n", A, B);
    return 0;
}
