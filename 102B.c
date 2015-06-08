#include <stdio.h>
#include <stdlib.h>

char Str[100001];

int main()
{
    int i, Sum, Cnt;
    scanf("%s", Str);
    if(Str[1] == '\0') {
        puts("0");
        return 0;
    }
    for(Cnt = 1, Sum = i = 0; Str[i] != '\0'; ++i) {
        Sum += Str[i] - '0';
    }
    while(Sum > 9) {
        itoa(Sum, Str, 10);
        for(Sum = i = 0; Str[i] != '\0'; ++i) {
            Sum += Str[i] - '0';
        }
        ++Cnt;
    }
    printf("%d\n", Cnt);
    return 0;
}
