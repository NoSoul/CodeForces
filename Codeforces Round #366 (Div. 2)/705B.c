#include <stdio.h>

int main()
{
    int n, Num;
    long long cur = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &Num);
        cur += Num - 1;
        printf("%d\n", cur & 1 ? 1 : 2);
    }
    return 0;
}
