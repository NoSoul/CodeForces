#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, N, x, y, v;
    float ans = 10000;
    scanf("%d %d %d", &a, &b, &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d %d", &x, &y, &v);
        float time = sqrt((x - a) * (x - a) + (y - b) * (y - b)) / v;
        if(time < ans) {
            ans = time;
        }
    }
    printf("%f\n", ans);
    return 0;
}
