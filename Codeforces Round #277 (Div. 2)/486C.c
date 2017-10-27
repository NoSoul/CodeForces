#include <stdio.h>

int Dis[100001];

int GetlettersDis(char a, char b)
{
    int ans = abs(a - b);
    if(ans > 13) {
        ans = 26 - ans;
    }
    return ans;
}

int main()
{
    int N, P, i, Ans, Left, Right, start, end;
    char Str[100001];
    scanf("%d %d", &N, &P);
    scanf("%s", Str);
    if(P > N / 2) {
        start = N - N / 2;
        end = N;
    } else {
        start = 0;
        end = N / 2;
    }
    --P;
    Ans = 0;
    for(i = start; i < end; ++i) {
        Dis[i] = GetlettersDis(Str[i], Str[N - 1 - i]);
        Ans += Dis[i];
    }
    if(Ans == 0) {
        printf("%d\n", Ans);
        return 0;
    }
    for(i = start; i < end; ++i) {
        if(Dis[i] > 0) {
            Left = i;
            break;
        }
    }
    for(i = end - 1; i >= start; --i) {
        if(Dis[i] > 0) {
            Right = i;
            break;
        }
    }
    Ans += Right - Left;
    if(abs(P - Left) > abs(P - Right)) {
        Ans += abs(P - Right);
    } else {
        Ans += abs(P - Left);
    }
    printf("%d\n", Ans);
    return 0;
}
