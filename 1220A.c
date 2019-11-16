#include <stdio.h>

int main()
{
    int n;
    char str[100001];
    int cnt0 = 0, cnt1 = 0;
    scanf("%d %s", &n, str);
    for(int i = 0; str[i]; ++i) {
        if(str[i] == 'n') {
            ++cnt1;
        }
        if(str[i] == 'z') {
            ++cnt0;
        }
    }
    for(int i = 0; i < cnt1; ++i) {
        printf("1 ");
    }
    for(int i = 0; i < cnt0; ++i) {
        printf("0 ");
    }
    return 0;
}
