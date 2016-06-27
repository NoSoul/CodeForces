#include <stdio.h>

int main()
{
    int sum = 0, ans;
    int T[5];
    for(int i = 0; i < 5; ++i) {
        scanf("%d", &T[i]);
        sum += T[i];
    }
    ans = sum;
    for(int i = 0; i < 4; ++i) {
        int k = i;
        for(int j = i + 1; j < 5; ++j) {
            if(T[j] > T[k]) {
                k = j;
            }
        }
        if(k != i) {
            int temp = T[k];
            T[k] = T[i];
            T[i] = temp;
        }
    }
    for(int i = 1; i < 5; ++i) {
        int cur = 0;
        if(T[i] == T[i - 1]) {
            cur = sum - T[i] - T[i - 1];
            if(i + 1 < 5 && T[i + 1] == T[i]) {
                cur -= T[i];
            }
            if(cur < ans) {
                ans = cur;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
