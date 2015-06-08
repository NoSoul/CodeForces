#include <stdio.h>

int main()
{
    int N, Max, i, Len;
    long long Sum = 0;
    int Value[26];
    char Str[1001];
    scanf("%s", Str);
    scanf("%d", &N);
    Max = 0;
    for(i = 0; i < 26; ++i) {
        scanf("%d", &Value[i]);
        if(Value[i] > Max) {
            Max = Value[i];
        }
    }
    for(Len = 0; Str[Len] != '\0'; ++Len) {
        Sum += (Len + 1) * Value[Str[Len] - 'a'];
    }
    for(i = 0; i < N; ++i, ++Len) {
        Sum += (Len + 1) * Max;
    }
    printf("%I64d\n", Sum);
    return 0;
}
