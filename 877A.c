#include <stdio.h>
#include <string.h>

int main()
{
    char name[][7] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
    char str[101];
    int cnt = 0;
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < 5; ++i) {
        char *p = str;
        while(1) {
            char *q = strstr(p, name[i]);
            if(q != NULL) {
                p = q + 1;
                ++cnt;
            } else {
                break;
            }
            if(p - str >= len) {
                break;
            }
        }
    }
    puts(cnt == 1 ? "YES" : "NO");
    return 0;
}
