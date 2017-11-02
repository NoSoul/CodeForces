#include <stdio.h>
#include <string.h>

char Name[100][101];

int main()
{
    int n, size = 0;;
    char str[101];
    scanf("%d", &n);
    while(n--) {
        scanf("%s", str);
        int i;
        for(i = 0; i < size; ++i) {
            if(strcmp(str, Name[i]) == 0) {
                puts("YES");
                break;
            }
        }
        if(i == size) {
            puts("NO");
            strcpy(Name[size++], str);
        }
    }
    return 0;
}
