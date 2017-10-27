#include <stdio.h>
#include <string.h>

char A[10];

int main()
{
    char Str[11], StrM[11];
    int i, Min = 0, Ans = 0;
    scanf("%s %s", Str, StrM);
    if(strlen(Str) != strlen(StrM)) {
        puts("WRONG_ANSWER");
        return 0;
    }
    for(i = 0; Str[i] != '\0'; ++i) {
        ++A[Str[i] - '0'];
    }
    for(i = 1; i < 10; ++i) {
        if(A[i]) {
            --A[i];
            Min = i;
            break;
        }
    }
    for(i = 0; i < 10; ++i) {
        while(A[i]) {
            Min *= 10;
            Min += i;
            --A[i];
        }
    }
    for(i = 0; StrM[i] != '\0'; ++i) {
        Ans *= 10;
        Ans += StrM[i] - '0';
    }
    puts(Ans == Min ? "OK" : "WRONG_ANSWER");
    return 0;
}
