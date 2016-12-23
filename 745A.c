#include <stdio.h>
#include <string.h>

char Visit[51];

int main()
{
    int Len, Ans = 0;
    char Str[51];
    scanf("%s", Str);
    Len = strlen(Str);
    for(int i = 0; i < Len; ++i) {
        if(!Visit[i]) {
            ++Ans;
            for(int j = 0; j < Len; ++j) {
                if(j != i) {
                    int k = 0;
                    for(k = 0; k < Len; ++k) {
                        if(Str[(i + k) % Len] != Str[(j + k) % Len]) {
                            break;
                        }
                    }
                    if(k == Len) {
                        Visit[j] = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", Ans);
    return 0;
}
