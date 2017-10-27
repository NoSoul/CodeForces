#include <stdio.h>

int Fun(int a, int b)
{
    int c = a - b;
    if(c < 0) {
        c += 26;
    }
    if(c > 13) {
        c = 26 - c;
    }
    return c;
}

int main()
{
    int idx = 0, Sum = 0;
    char Str[101];
    scanf("%s", Str);
    for(int i = 0; Str[i] != '\0'; ++i) {
        Sum += Fun(idx, Str[i] - 'a');
        idx = Str[i] - 'a';
    }
    printf("%d\n", Sum);
    return 0;
}
