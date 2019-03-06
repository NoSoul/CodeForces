#include <stdio.h>

int main()
{
    int cnt1, cnt2, cnt3, cnt4;
    scanf("%d %d %d %d", &cnt1, &cnt2, &cnt3, &cnt4);
    if(cnt3) {
        puts(cnt1 && cnt1 == cnt4 ? "1" : "0");
    } else {
        puts(cnt1 == cnt4 ? "1" : "0");
    }
    return 0;
}
