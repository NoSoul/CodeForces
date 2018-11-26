#include <stdio.h>
#include <string.h>

int main()
{
    char S[200001];
    char T[200001];
    int lenS, lenT, ans;
    scanf("%s %s", S, T);
    lenS = strlen(S);
    lenT = strlen(T);
    ans = lenS + lenT;
    for(int i = lenS - 1, j = lenT - 1; i >= 0 && j >= 0; --i, --j) {
        if(S[i] != T[j]) {
            break;
        }
        ans -= 2;
    }
    printf("%d\n", ans);
    return 0;
}
