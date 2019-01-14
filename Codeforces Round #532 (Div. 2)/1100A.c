#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    int A[100];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    int ans = 0;
    for(int i = 0; i < k; ++i) {
        int e = 0;
        int s = 0;
        for(int j = 0; j < n; ++j) {
            if((j - i + n) % k != 0) {
                if(A[j] == 1) {
                    ++e;
                } else {
                    ++s;
                }
            }
        }
        if(ans < abs(e - s)) {
            ans = abs(e - s);
        }
    }
    printf("%d", ans);
    return 0;
}
