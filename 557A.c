#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int main()
{
    int N, i;
    int min[3], max[3];
    scanf("%d", &N);
    for(i = 0; i < 3; ++i) {
        scanf("%d %d", &min[i], &max[i]);
    }
    int cur = MIN(N - min[1] - min[2], max[0]);
    printf("%d ", cur);
    N -= cur;
    cur = MIN(N - min[2], max[1]);
    printf("%d %d\n", cur, N - cur);
    return 0;
}
