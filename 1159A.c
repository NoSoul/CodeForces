#include <stdio.h>

int main()
{
    int n, offset = 0, min = 0;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        if(str[i] == '-') {
            --offset;
            if(min > offset) {
                min = offset;
            }
        } else {
            ++offset;
        }
    }
    printf("%d\n", offset - min);
    return 0;
}
