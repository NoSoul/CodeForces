#include <stdio.h>

int main()
{
    char str[100001];
    scanf("%s", str);
    int j = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] <= 'a' + j) {
            str[i] = 'a' + j;
            if(++j == 26) {
                break;
            }
        }
    }
    puts(j == 26 ? str : "-1");
    return 0;
}
