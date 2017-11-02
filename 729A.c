#include <stdio.h>

int main()
{
    int n;
    char str[101];
    scanf("%d %s", &n, str);
    for(int i = 0; i < n; ++i) {
        char flag = 0;
        if(str[i] == 'o') {
            while(i + 2 < n && str[i + 1] == 'g' && str[i + 2] == 'o') {
                flag = 1;
                i += 2;
            }
            if(flag) {
                printf("***");
            }
        }
        if(!flag) {
            printf("%c", str[i]);
        }
    }
    puts("");
    return 0;
}
