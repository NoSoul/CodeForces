#include <stdio.h>

char Flag[100001];

int main()
{
    int n, a;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d", &a);
        Flag[a] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(!Flag[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}
