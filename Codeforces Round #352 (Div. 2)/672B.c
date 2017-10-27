#include <stdio.h>

char Num[26];

int main()
{
    int N, i;
    char ch;
    scanf("%d\n", &N);
    if(N > 26) {
        puts("-1");
    } else {
        for(i = 0; i < N; ++i) {
            scanf("%c", &ch);
            Num[ch - 'a'] = 1;
        }
        for(i = 0; i < 26; ++i) {
            if(Num[i]) {
                --N;
            }
        }
        printf("%d\n", N);
    }
    return 0;
}
