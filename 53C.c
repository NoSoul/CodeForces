#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1, j = n; i <= j; ++i, --j) {
        if(i != j) {
            printf("%d %d ", i, j);
        } else {
            printf("%d ", i);
        }
    }
    return 0;
}
