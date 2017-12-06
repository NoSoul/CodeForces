#include <stdio.h>

int main()
{
    int n;
    char pass[3];
    char str[100][3];
    scanf("%s %d", pass, &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str[i]);
        if(str[i][0] == pass[0] && str[i][1] == pass[1]) {
            puts("YES");
            return 0;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if((str[i][1] == pass[0] && str[j][0] == pass[1]) || (str[i][0] == pass[1] && str[j][1] == pass[0])) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
