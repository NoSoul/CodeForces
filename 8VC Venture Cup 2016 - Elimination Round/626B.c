#include <stdio.h>

int Cnt[3];

int Impossible(int a, int b, int c)
{
    if((!c && !a) || (!c && !b)) {
        return 1;
    }
    if(!a && b == 1) {
        return 1;
    }
    if(!b && a == 1) {
        return 1;
    }
    return 0;
}

int main()
{
    int N, i;
    char Str[201];
    scanf("%d %s", &N, Str);
    for(i = 0; i < N; ++i) {
        if(Str[i] == 'B') {
            ++Cnt[0];
        } else if(Str[i] == 'G') {
            ++Cnt[1];
        } else {
            ++Cnt[2];
        }
    }
    if(!Impossible(Cnt[1], Cnt[2], Cnt[0])) {
        printf("B");
    }
    if(!Impossible(Cnt[0], Cnt[2], Cnt[1])) {
        printf("G");
    }
    if(!Impossible(Cnt[0], Cnt[1], Cnt[2])) {
        printf("R");
    }
    puts("");
    return 0;
}
