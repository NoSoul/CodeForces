#include <stdio.h>

int main()
{
    int Cnt, cur;
    int A[100];
    char Str[101];
    scanf("%*d %s", Str);
    Cnt = cur = 0;
    for(int i = 0; Str[i] != '\0'; ++i) {
        if(Str[i] == 'B') {
            ++cur;
        } else {
            if(cur) {
                A[Cnt++] = cur;
                cur = 0;
            }
        }
    }
    if(cur) {
        A[Cnt++] = cur;
        cur = 0;
    }
    printf("%d\n", Cnt);
    for(int i = 0; i < Cnt; ++i) {
        printf("%d ", A[i]);
    }
    puts("");
    return 0;
}
