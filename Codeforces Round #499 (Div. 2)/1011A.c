#include <stdio.h>

int Cnt[26];

int main()
{
    int n, k;
    char str[51];
    scanf("%d %d %s", &n, &k, str);
    for(int i = 0; str[i] != '\0'; ++i) {
        ++Cnt[str[i] - 'a'];
    }
    int j = 0, ans = 0, choice = 0;
    while(1) {
        int i;
        for(i = j; i < 26; ++i) {
            if(Cnt[i]) {
                ans += i + 1;
                ++choice;
                j = i + 2;
                break;
            }
        }
        if(i >= 26 || choice == k) {
            break;
        }
    }
    if(choice == k) {
        printf("%d\n", ans);
    } else {
        puts("-1");
    }
    return 0;
}
