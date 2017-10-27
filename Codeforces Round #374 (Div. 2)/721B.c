#include <stdio.h>
#include <string.h>

int A[101];

int main()
{
    int n, k, targetLen;
    char Str[101];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%s", Str);
        A[strlen(Str)]++;
    }
    scanf("%s", Str);
    targetLen = strlen(Str);
    int remain = 0;
    for(int i = 1; i < targetLen; ++i) {
        remain += A[i];
    }
    printf("%d ", (remain / k) * 5 + remain + 1);
    remain += A[targetLen] - 1;
    printf("%d\n", (remain / k) * 5 + remain + 1);
    return 0;
}
