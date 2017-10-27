#include <stdio.h>

int main()
{
    int N, i, flag = 0;
    char Str[101];
    scanf("%d %s", &N, Str);
    for(i = 0; i <= N; i += 3) {
        if(!((N - i) & 1)) {
            int y = i / 3;
            int x = (N - i) >> 1;
            int j = 0;
            while(x--) {
                if(flag) {
                    putchar('-');
                }
                putchar(Str[j++]);
                putchar(Str[j++]);
                if(!flag) {
                    flag = 1;
                }
            }
            while(y--) {
                if(flag) {
                    putchar('-');
                }
                putchar(Str[j++]);
                putchar(Str[j++]);
                putchar(Str[j++]);
                if(!flag) {
                    flag = 1;
                }
            }
            puts("");
            return 0;
        }
    }
    return 0;
}
