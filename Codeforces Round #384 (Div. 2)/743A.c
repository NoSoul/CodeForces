#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b;
    char Str[100001];
    scanf("%d %d %d", &n, &a, &b);
    scanf("%s", Str);
    --a;
    --b;
    puts(Str[a] == Str[b] ? "0" : "1");
    return 0;
}
