#include <stdio.h>

int Cnt[200001];

int main()
{
    int n;
    int A[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        for(int j = 0; j < i; ++j) {
            ++Cnt[A[i] + A[j]];
        }
    }
    int ans = 0;
    for(int i = 0; i < 200001; ++i) {
        if(ans < Cnt[i]) {
            ans = Cnt[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
