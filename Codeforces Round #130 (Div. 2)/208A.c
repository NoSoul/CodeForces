#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, L, k;
    char Str[201], out[201];
    scanf("%s", Str);
    L = strlen(Str);
    for(k = i = j = 0; i < L; ++i) {
        if(i < L - 2 && Str[i] == 'W' && Str[i + 1] == 'U' && Str[i + 2] == 'B') {
            if(j) {
                out[j] = '\0';
                printf("%s", out);
                if(i == L - 3) {
                    j = 0;
                    break;
                }
                if(k) {
                    printf(" ");
                }
                k = 1;
            }
            i += 2;
            j = 0;
        } else {
            out[j++] = Str[i];
            k = 1;
        }
    }
    if(j) {
        out[j] = '\0';
        printf("%s", out);
    }
    return 0;
}
