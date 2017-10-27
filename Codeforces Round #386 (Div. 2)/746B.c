#include <stdio.h>

int main()
{
    int N;
    char Str[2001];
    scanf("%d %s", &N, Str);
    if(N == 1) {
        puts(Str);
    } else {
        int start = (N & 1) ? 1 : 0;
        while(start + 2 < N) {
            start += 2;
        }
        while(start >= 0) {
            putchar(Str[start]);
            start -= 2;
        }
        if(N & 1) {
            putchar(Str[0]);
        }
        start = (N & 1) ? 2 : 1;
        while(start < N) {
            putchar(Str[start]);
            start += 2;
        }
        putchar('\n');
    }
    return 0;
}
