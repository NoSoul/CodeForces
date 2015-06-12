#include <stdio.h>
#include <string.h>

int main()
{
    char Str[201];
    int i, j, k, K, L;
    scanf("%s %d", Str, &K);
    L = strlen(Str);
    if(K >= L) {
        printf("%d\n", (K + L) / 2 * 2);
        return 0;
    }
    for(i = (K + L) / 2; i > 0; --i) {
        for(j = 0; j + 2 * i <= L + K; ++j) {
            for(k = j + i; k < L && k < j + 2 * i; ++k) {
                if(Str[k] != Str[k - i]) {
                    break;
                }
            }
            if(k == L || k == j + 2 * i) {
                printf("%d\n", 2 * i);
                return 0;
            }
        }
    }
    puts("0");
    return 0;
}
