#include <stdio.h>

int Cnt[101];

int main()
{
    int n, a, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++Cnt[a];
        sum += a;
    }
    int max = 0;
    for(int x = 1; x < 101; ++x) {
        for(int i = 1; i < 101; ++i) {
            if(Cnt[i] && i % x == 0) {
                for(int j = 1; j < 101; ++j) {
                    if(Cnt[j]) {
                        int cur = i + j - i / x - j * x;
                        if(max < cur) {
                            max = cur;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", sum - max);
    return 0;
}
