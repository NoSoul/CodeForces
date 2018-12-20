#include <stdio.h>

int Cnt[1000001];
int ans[200001];

int main()
{
    int n;
    long long sum = 0;
    int a[200001];
    int size = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        ++Cnt[a[i]];
    }
    for(int i = 0; i < n; ++i) {
        --Cnt[a[i]];
        long long sumPrime = sum - a[i];
        if(!(sumPrime & 1) && sumPrime / 2 < 1000001 && Cnt[sumPrime / 2] > 0) {
            ans[size++] = i + 1;
        }
        ++Cnt[a[i]];
    }
    printf("%d\n", size);
    for(int i = 0; i < size; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}
