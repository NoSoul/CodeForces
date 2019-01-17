#include <stdio.h>

char Str[200001];

int main()
{
    int N, Ans = 0;
    scanf("%d %s", &N, Str);
    for(int i = 0; i < N; ++i) {
        if(Str[i] == '>') {
            break;
        }
        ++Ans;
    }
    for(int i = N - 1; i >= 0; --i) {
        if(Str[i] == '<') {
            break;
        }
        ++Ans;
    }
    printf("%d\n", Ans);
    return 0;
}
