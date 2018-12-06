#include <stdio.h>
#include <math.h>

int Cnt[6];

int main()
{
    int n, a, sum = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        sum += a;
        ++Cnt[a];
    }
    while(1) {
        int avg = round(1.0 * sum / n);
        if(avg == 5) {
            break;
        }
        for(int i = 2; i < 5; ++i) {
            if(Cnt[i]) {
                --Cnt[i];
                ++Cnt[5];
                ++ans;
                sum += 5 - i;
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
