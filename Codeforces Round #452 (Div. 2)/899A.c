#include <stdio.h>

int main()
{
    int n, cnt1, cnt2, a;
    cnt1 = cnt2 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if(a == 1) {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }
    int min = cnt1;
    if(min > cnt2) {
        min = cnt2;
    }
    printf("%d\n", min + (cnt1 - min) / 3);
    return 0;
}
