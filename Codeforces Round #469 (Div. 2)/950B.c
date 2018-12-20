#include <stdio.h>

int main()
{
    int n, m;
    int x[100001];
    int y[100001];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d", &y[i]);
    }
    int i = 1, j = 1;
    int sumA, sumB;
    sumA = x[0];
    sumB = y[0];
    int ans = 0;
    while(1) {
        if(sumA < sumB) {
            sumA += x[i++];
        } else if(sumA > sumB) {
            sumB += y[j++];
        }
        if(sumA == sumB) {
            ++ans;
            if(i == n && j == m) {
                break;
            }
            sumA += x[i++];
            sumB += y[j++];
        }
    }
    printf("%d\n", ans);
    return 0;
}
