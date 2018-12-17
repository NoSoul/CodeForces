#include <stdio.h>
#include <string.h>

int Cnt[9];
char Match[][5] = {"XXXS", "XXS", "XS", "S", "M", "L", "XL", "XXL", "XXXL"};

int main()
{
    int n;
    char str[5];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < 9; ++j) {
            if(strcmp(str, Match[j]) == 0) {
                ++Cnt[j];
                break;
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        for(int j = 0; j < 9; ++j) {
            if(strcmp(str, Match[j]) == 0) {
                if(Cnt[j]) {
                    --Cnt[j];
                }
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 9; ++i) {
        ans += Cnt[i];
    }
    printf("%d\n", ans);
    return 0;
}
