#include <stdio.h>
#include <string.h>

int main()
{
    char strA[102];
    char strB[102];
    scanf("%s %s", strA, strB);
    if(strcmp(strA, strB) == 0) {
        puts(strA);
    } else {
        puts("1");
    }
    return 0;
}
