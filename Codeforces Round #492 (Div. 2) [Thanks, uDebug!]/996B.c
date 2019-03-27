#include <stdio.h>

int main()
{
    int n, a, minIdx, minTime = 0x7fffffff;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        int curTime = a / n * n;
        if(a % n > i) {
            curTime += n;
        }
        curTime += i;
        if(minTime > curTime) {
            minTime = curTime;
            minIdx = i + 1;
        }
    }
    printf("%d\n", minIdx);
    return 0;
}
