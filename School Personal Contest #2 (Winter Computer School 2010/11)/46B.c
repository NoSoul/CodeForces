#include <stdio.h>
#include <string.h>

int main()
{
    int Cnt[5], K;
    for(int i = 0; i < 5; ++i) {
        scanf("%d", &Cnt[i]);
    }
    scanf("%d", &K);
    char str[4];
    char match[5][4] = {"S", "M", "L", "XL", "XXL"};
    for(int i = 0; i < K; ++i) {
        scanf("%s", str);
        for(int j = 0; j < 5; ++j) {
            if(strcmp(str, match[j]) == 0) {
                if(Cnt[j]) {
                    --Cnt[j];
                    printf("%s\n", match[j]);
                } else {
                    for(int offet = 1; offet < 5; ++offet) {
                        int pre = j - offet >= 0 && Cnt[j - offet];
                        int suf = j + offet < 5 && Cnt[j + offet];
                        if(pre && suf) {
                            --Cnt[j + offet];
                            printf("%s\n", match[j + offet]);
                            break;
                        } else if(suf) {
                            --Cnt[j + offet];
                            printf("%s\n", match[j + offet]);
                            break;
                        } else if(pre) {
                            --Cnt[j - offet];
                            printf("%s\n", match[j - offet]);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    return 0;
}
