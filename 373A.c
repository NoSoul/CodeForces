#include <stdio.h>

int Hash[10];

int main()
{
    int i, j, K;
    char Str[5];
    scanf("%d", &K);
    for(j = 0; j < 4; ++j) {
        scanf("%s", Str);
        for(i = 0; Str[i] != '\0'; ++i) {
            if(Str[i] == '.') {
                continue;
            }
            ++Hash[Str[i] - '0'];
        }
    }
    for(i = 1; i < 10 && Hash[i] <= 2 * K; ++i);
    puts(i == 10 ? "YES" : "NO");
    return 0;
}
