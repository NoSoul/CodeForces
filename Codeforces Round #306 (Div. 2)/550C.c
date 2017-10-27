#include <stdio.h>
#include <string.h>

int main()
{
    char Str[101];
    char template[3];
    int i, j, L;
    scanf("%s", Str);
    L = strlen(Str);
    for(i = 0; i < 1000; i += 8) {
        memset(template, -1, sizeof(template));
        int Lprime = 0;
        int num = i;
        do {
            template[Lprime++] = num % 10 + '0';
            num /= 10;
        } while(num != 0);
        int cur = L - 1;
        for(j = 0; j < Lprime; ++j) {
            while(cur >= 0 && Str[cur] != template[j]) {
                if(--cur < 0) {
                    break;
                }
            }
            if(cur < 0) {
                break;
            }
            --cur;
        }
        if(j == Lprime) {
            puts("YES");
            printf("%d\n", i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}
