#include <stdio.h>

int main()
{
    int n, m, z, sum = 0;
    scanf("%d %d %d", &n, &m, &z);
    for(int i = 1; i <= z; ++i) {
        if(i % n == 0 && i % m == 0) {
            ++sum;
        }
    }
    printf("%d\n", sum);
    return 0;
}
