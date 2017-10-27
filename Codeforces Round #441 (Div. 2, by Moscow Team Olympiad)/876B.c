#include <stdio.h>

int Cnt[100000];
int A[100000];

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        ++Cnt[A[i] % m];
    }
    for(int i = 0; i < m; ++i) {
        if(Cnt[i] >= k) {
            puts("Yes");
            for(int j = 0, l = 0; j < n && l < k; ++j) {
                if(A[j] % m == i) {
                    printf("%d ", A[j]);
                    ++l;
                }
            }
            puts("");
            return 0;
        }
    }
    puts("No");
    return 0;
}
