#include <stdio.h>

int GetSum(int *array, int *l, int *r, int m)
{
    int ret = 0;
    for(int i = 0; i < m; ++i) {
        int roses = 0, lilies = 0;
        for(int j = l[i]; j <= r[i]; ++j) {
            if(array[j]) {
                ++lilies;
            } else {
                ++roses;
            }
        }
        ret += roses * lilies;
    }
    return ret;
}

int main()
{
    int n, m;
    int ansA[1001];
    int ansB[1001];
    int l[1000];
    int r[1000];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &l[i], &r[i]);
    }
    int cur = 0;
    for(int i = 1; i <= n; ++i) {
        ansA[i] = i & 1;
        ansB[i] = ~(i & 1);
    }
    if(GetSum(ansA, l, r, m) > GetSum(ansB, l, r, m)) {
        for(int i = 1; i <= n; ++i) {
            printf("%d", i & 1);
        }
    } else {
        for(int i = 1; i <= n; ++i) {
            printf("%d", !(i & 1));
        }
    }
    return 0;
}
