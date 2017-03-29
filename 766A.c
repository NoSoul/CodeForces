#include <stdio.h>
#include <string.h>

int main()
{
    char strA[100001];
    char strB[100001];
    scanf("%s %s", strA, strB);
    int len = strlen(strA);
    if((unsigned)len < strlen(strB)) {
        len = strlen(strB);
    }
    printf("%d\n", strcmp(strA, strB) == 0 ? -1 : len);
    return 0;
}
