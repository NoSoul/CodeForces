#include <stdio.h>

int main()
{
    int x[4];
    int max = 0;
    for(int i = 0; i < 4; ++i) {
        scanf("%d", &x[i]);
        if(max < x[i]) {
            max = x[i];
        }
    }
    for(int i = 0; i < 4; ++i) {
        if(max != x[i]) {
            printf("%d ", max - x[i]);
        }
    }
    return 0;
}
