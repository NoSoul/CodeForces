#include <stdio.h>

long long Sum(int x)
{
    return ((long long)x) * (x + 1) / 2;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int left = 1;
    int right = n;
    while(left < right) {
        int mid = (left + right) >> 1;
        if(Sum(mid) < k) {
            left = mid + 1;
        } else {
            if(Sum(mid) - (n - mid) > k) {
                right = mid - 1;
            } else if(Sum(mid) - (n - mid) == k) {
                left = mid;
                break;
            } else {
                left = mid + 1;
            }
        }
    }
    printf("%d\n", n - left);
    return 0;
}
