#include <stdio.h>

int main()
{
    int n, m, Ans = 0;
    int A[100];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    while(m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l;
        --r;
        int sum = 0;
        for(int i = l; i <= r; ++i) {
            sum += A[i];
        }
        if(sum > 0) {
            Ans += sum;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
