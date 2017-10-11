#include <stdio.h>

char Flag[100001];

int main()
{
    int n, a, bound;
    scanf("%d", &n);
    bound = n;
    while(n--) {
        scanf("%d", &a);
        Flag[a] = 1;
        while(Flag[bound]) {
            printf("%d ", bound);
            --bound;
        }
        puts("");
    }
    return 0;
}
