#include <stdio.h>

int main()
{
    int n;
    char str[101];
    scanf("%d %s", &n, str);
    int Cnt[2] = {0};
    for(int i = 0; str[i]; ++i) {
        ++Cnt[str[i] - '0'];
    }
    if(Cnt[0] == Cnt[1]) {
        printf("2\n%c %s\n", str[0], str + 1);
    } else {
        printf("1\n%s\n", str);
    }
    return 0;
}
