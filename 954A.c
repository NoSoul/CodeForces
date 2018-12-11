#include <stdio.h>

int main()
{
    int n, cnt = 0;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 1; str[i]; ++i) {
        if(str[i] != str[i - 1]) {
            str[i] = str[i + 1];
            ++cnt;
        }
    }
    printf("%d\n", n - cnt);
    return 0;
}
