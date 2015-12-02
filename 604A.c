#include <stdio.h>

int main()
{
    int M[5], W[5], hs, hu, i;
    int sum = 0;
    for(i = 0; i < 5; ++i) {
        scanf("%d", &M[i]);
    }
    for(i = 0; i < 5; ++i) {
        scanf("%d", &W[i]);
    }
    scanf("%d %d", &hs, &hu);
    for(i = 0; i < 5; ++i) {
        int x = (i + 1) * 500;
        sum += 3 * x / 10 > (250 -  M[i]) * 2 * (i + 1)  - 50 * W[i] ? 3 * x / 10 : (250 -  M[i]) * 2 * (i + 1)  - 50 * W[i];
    }
    sum += 100 * hs;
    sum -= 50 * hu;
    printf("%d\n", sum);
    return 0;
}
