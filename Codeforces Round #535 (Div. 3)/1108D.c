#include <stdio.h>

int main()
{
    int n;
    char str[200001];
    char match[3] = "RGB";
    scanf("%d %s", &n, &str);
    int cnt = 0;
    for(int i = 1; str[i]; ++i) {
        if(str[i] == str[i - 1]) {
            ++cnt;
            for(int j = 0; j < 3; ++j) {
                if(match[j] != str[i - 1] && match[j] != str[i + 1]) {
                    str[i] = match[j];
                    break;
                }
            }
        }
    }
    printf("%d\n%s", cnt, str);
    return 0;
}
