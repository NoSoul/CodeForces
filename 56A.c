#include <stdio.h>
#include <string.h>

int main()
{
    int n, ans = 0;
    char match[][10] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    char str[101];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        if(str[0] >= '0' && str[0] <= '9') {
            int age;
            sscanf(str, "%d", &age);
            if(age < 18) {
                ++ans;
            }
        } else {
            for(int i = 0; i < 11; ++i) {
                if(strcmp(str, match[i]) == 0) {
                    ++ans;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
