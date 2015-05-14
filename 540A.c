#include <stdio.h>

int main()
{
    int N, i, Ans = 0;
    char Str1[1001], Str2[1001];
    scanf("%d %s %s", &N, Str1, Str2);
    for(i = 0; Str1[i] != '\0'; ++i)
    {
        int a = Str1[i] - '0';
        int b = Str2[i] - '0';
        Ans += abs(a - b) > 5 ? 10 - abs(a - b) : abs(a - b);
    }
    printf("%d\n", Ans);
    return 0;
}
