#include <stdio.h>

#define MAXN    300001
char Str[MAXN];
int Size;

int main()
{
    int N, M, x, i, Ans = 0;
    char c[2];
    scanf("%d %d", &N, &M);
    scanf("%s", Str);
    for(i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == '.') {
            ++Size;
        } else {
            if(Size) {
                Ans += Size - 1;
            }
            Size = 0;
        }
    }
    if(Size) {
        Ans += Size - 1;
    }
    while(M--) {
        scanf("%d %s", &x, c);
        --x;
        if(Str[x] == '.') {
            if(c[0] != '.') {
                if(x > 0 && Str[x - 1] == '.') {
                    --Ans;
                }
                if(x < N - 1 && Str[x + 1] == '.') {
                    --Ans;
                }
            }
        } else {
            if(c[0] == '.') {
                if(x > 0 && Str[x - 1] == '.') {
                    ++Ans;
                }
                if(x < N - 1 && Str[x + 1] == '.') {
                    ++Ans;
                }
            }
        }
        Str[x] = c[0];
        printf("%d\n", Ans);
    }
    return 0;
}
