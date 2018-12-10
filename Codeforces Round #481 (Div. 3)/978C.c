#include <stdio.h>

long long Sum[200001];

int main()
{
    int n, m;
    long long a, b;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%I64d", &a);
        Sum[i] = Sum[i - 1] + a;
    }
    while(m--) {
        scanf("%I64d", &b);
        int l = 0;
        int r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(b <= Sum[mid] && b > Sum[mid - 1]) {
                printf("%d %I64d\n", mid, b - Sum[mid - 1]);
                break;
            } else if(b > Sum[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
    }
    return 0;
}
