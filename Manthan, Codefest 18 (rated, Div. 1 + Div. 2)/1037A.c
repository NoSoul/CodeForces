#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int step = 1;
    while(1) {
        if(n < (1 << step)) {
            printf("%d\n", step);
            break;
        }
        ++step;
    }
    return 0;
}
