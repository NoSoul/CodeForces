#include <stdio.h>

int Hash[100];

int main()
{
    int N, i, j, l, r, Sum = 0;
    scanf("%d", &N);
    for(i = 0; i < 100; ++i) {
        Hash[i] = -1;
    }
    for(i = 0; i < N; ++i) {
        scanf("%d %d", &l, &r);
        for(j = l; j < r; ++j) {
            Hash[j] = i;
        }
    }
    for(i = 0; i < 100; ++i) {
        Sum += Hash[i] == 0;
    }
    printf("%d\n", Sum);
    return 0;
}
