#include <stdio.h>

int main()
{
    int n, min = 0x7fffffff;
    int v[1000];
    long long s;
    scanf("%d %I64d", &n, &s);
    long long remain = 0;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        if(min > v[i]) {
            min = v[i];
        }
    }
    for(int i = 0; i < n; ++i) {
        remain += v[i] - min;
    }
    if(remain >= s) {
        printf("%d\n", min);
    } else {
        s -= remain;
        if(s > (long long)min * n) {
            puts("-1");
        } else {
            printf("%d\n", min - s / n - (s % n != 0));
        }
    }
    return 0;
}
