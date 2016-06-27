#include <stdio.h>

char Flag[100];

int main()
{
    int N, a, ans;
    scanf("%d %d", &N, &a);
    --a;
    for(int i = 0; i < N; ++i) {
        scanf("%hhd", &Flag[i]);
    }
    ans = Flag[a];
    for(int i = 1; i < N; ++i) {
        char left = a - i >= 0 && a - i < N;
        char right = a + i >= 0 && a + i < N;
        if(left) {
            if(right) {
                ans += (Flag[a - i] && Flag[a + i]) ? 2 : 0;
            } else {
                ans += Flag[a - i];
            }
        } else {
            if(right) {
                ans += Flag[a + i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
