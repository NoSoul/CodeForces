#include <stdio.h>
#include <string.h>

int Palindrome(char *str, int i, int j)
{
    while(i < j) {
        if(str[i] != str[j]) {
            return 0;
        }
        ++i;
        --j;
    }
    return 1;
}

int main()
{
    int max = 0;
    char str[51];
    scanf("%s", &str);
    int len = strlen(str);
    for(int i = 0; i < len - 1; ++i) {
        for(int j = i + 1; j < len; ++j) {
            if(!Palindrome(str, i, j)) {
                if(max < j - i + 1) {
                    max = j - i + 1;
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}
