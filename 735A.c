#include <stdio.h>

int main()
{
    int N, K, G, T;
    char Str[101];
    scanf("%d %d %s", &N, &K, Str);
    for(int i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'G') {
            G = i;
        }
        if(Str[i] == 'T') {
            T = i;
        }
    }
    if(G > T) {
        K = -K;
    }
    int s = G;
    while(1) {
        s += K;
        if(s < 0 || s >= N) {
            puts("NO");
            return 0;
        }
        if(Str[s] == '#') {
            puts("NO");
            return 0;
        }
        if(Str[s] == 'T') {
            break;
        }
    }
    puts("YES");
    return 0;
}
