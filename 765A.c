#include <stdio.h>
#include <string.h>

int main()
{
    int n, cnt = 0;
    char home[4], flights[9];
    scanf("%d %s", &n, home);
    for(int i = 0; i < n; ++i) {
        scanf("%s", flights);
        if(strncmp(home, flights, 3) == 0) {
            ++cnt;
        } else {
            --cnt;
        }
    }
    puts(cnt == 0 ? "home" : "contest");
    return 0;
}
