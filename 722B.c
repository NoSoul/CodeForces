#include <stdio.h>

int main()
{
    int N, P[100];
    char Str[103];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &P[i]);
    }
    scanf("\n");
    for(int i = 0; i < N; ++i) {
        fgets(Str, 102, stdin);
        int cnt = 0;
        for(int j = 0; Str[j] != '\0'; ++j) {
            if(Str[j] == 'a' || Str[j] == 'e' || Str[j] == 'i' || Str[j] == 'o' || Str[j] == 'u' || Str[j] == 'y') {
                ++cnt;
            }
        }
        if(cnt != P[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
