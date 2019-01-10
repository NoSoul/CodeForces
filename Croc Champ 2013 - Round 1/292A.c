#include <stdio.h>

int main()
{
    int n, t, c;
    int size = 0, lastTime = 0, max = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {

        scanf("%d %d", &t, &c);
        if(size > t - lastTime) {
            size -= t - lastTime;
        } else {
            size = 0;
        }
        size += c;
        if(max < size) {
            max = size;
        }
        lastTime = t;
    }
    lastTime += size;
    printf("%d %d\n", lastTime, max);
    return 0;
}
