#include <stdio.h>

int main()
{
    int n;
    char str[200001];
    scanf("%d%s", &n, str);
    int ans = 0;
    for(int i = 0; str[i]; i += 2) {
        if(str[i] == str[i + 1]) {
            ++ans;
            if(str[i] == 'a') {
                str[i] = 'b';
            } else {
                str[i] = 'a';
            }
        }
    }
    printf("%d\n%s\n", ans, str);
    return 0;
}
