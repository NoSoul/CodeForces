#include <stdio.h>

int main()
{
    char match[] = "heidi";
    char str[1001];
    scanf("%s", &str);
    int pos = 0;
    for(int i = 0; str[i]; ++i) {
        if(str[i] == match[pos]) {
            ++pos;
            if(pos == 5) {
                break;
            }
        }
    }
    puts(pos == 5 ? "YES" : "NO");
    return 0;
}
