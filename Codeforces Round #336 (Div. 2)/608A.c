#include <stdio.h>

int A[1001];

int main()
{
    int n, s, i, f, t, Ans = 0;
    scanf("%d %d", &n, &s);
    for(i = 0; i < n; ++i) {
        scanf("%d %d", &f, &t);
        if(A[f] < t) {
            A[f] = t;
        }
    }
    for(i = s; i >= 0; --i) {
        if(Ans < A[i]) {
            Ans = A[i];
        }
        if(i) {
            ++Ans;
        }
    }
    printf("%d\n", Ans);
    return 0;
}
