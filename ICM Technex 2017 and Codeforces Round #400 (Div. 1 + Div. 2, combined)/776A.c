#include <stdio.h>
#include <string.h>

int main()
{
    char StrA[11], StrB[11];
    char StrC[11], StrD[11];
    int n;
    scanf("%s %s", StrA, StrB);
    scanf("%d", &n);
    printf("%s %s\n", StrA, StrB);
    while(n--) {
        scanf("%s %s", StrC, StrD);
        if(strcmp(StrC, StrA) == 0) {
            memcpy(StrA, StrD, sizeof(StrA));
        } else if(strcmp(StrC, StrB) == 0) {
            memcpy(StrB, StrD, sizeof(StrB));
        }
        printf("%s %s\n", StrA, StrB);
    }
    return 0;
}
