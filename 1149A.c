#include <stdio.h>

int main()
{
    int n, a;
    int cnt[3] = {0};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++cnt[a];
    }
    if(cnt[2]) {
        --cnt[2];
        printf("2 ");
    }
    if(cnt[1]) {
        --cnt[1];
        printf("1 ");
    }
    for(int i = 0; i < cnt[2]; ++i) {
        printf("2 ");
    }
    for(int i = 0; i < cnt[1]; ++i) {
        printf("1 ");
    }
    return 0;
}
