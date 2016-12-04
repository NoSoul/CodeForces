#include <stdio.h>

int Min(int a, int b)
{
    if(a < b) {
        return a;
    }
    return b;
}

int main()
{
    int k2, k3, k5, k6, minNum;
    scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
    minNum = Min(k5, k6);
    minNum = Min(k2, minNum);
    k2 -= minNum;
    k5 -= minNum;
    k6 -= minNum;
    printf("%d\n", minNum * 256 + Min(k2, k3) * 32);
    return 0;
}
