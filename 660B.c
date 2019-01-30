#include <stdio.h>

int Func(int x, int y, int n)
{
    if(y == 0) {
        return x * 2 + 1;
    } else if(y == 3) {
        return x * 2 + 2;
    } else if(y == 1) {
        return 2 * n + x * 2 + 1;
    }
    return 2 * n + x * 2 + 2;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int step[4] = {1, 0, 2, 3};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 4; ++j) {
            int sn = Func(i, step[j], n);
            if(sn <= m) {
                printf("%d ", sn);
            }
        }
    }
    return 0;
}
