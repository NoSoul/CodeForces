#include <stdio.h>

long long Sum[200001];

int main()
{
    int n, d;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &d);
        Sum[i] = Sum[i - 1] + d;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int l = i;
        int r = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(Sum[n] - Sum[mid] == Sum[i]) {
                ans = i;
                break;
            } else if(Sum[n] - Sum[mid] > Sum[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    printf("%I64d\n", Sum[ans]);
    return 0;
}
