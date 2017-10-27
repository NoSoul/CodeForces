#include <stdio.h>

char Flag[26];

int main()
{
    char str[1001];
    int k;
    scanf("%s %d", str, &k);
    int len = 0, count = 0;
    for(int i = 0; str[i]; ++i) {
        if(!Flag[str[i] - 'a']) {
            Flag[str[i] - 'a'] = 1;
            ++count;
        }
        ++len;
    }
    if(len < k) {
        puts("impossible");
    } else {
        printf("%d\n", k > count ? k - count : 0);
    }
    return 0;
}
