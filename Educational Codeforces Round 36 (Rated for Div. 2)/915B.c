#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, pos, l, r;
    scanf("%d %d %d %d", &n, &pos, &l, &r);
    if(l == 1 && r == n) {
        puts("0");
    } else if(l == 1) {
        printf("%d\n", abs(r - pos) + 1);
    } else if(r == n) {
        printf("%d\n", abs(l - pos) + 1);
    } else {
        int min = abs(pos - l);
        if(min > abs(pos - r)) {
            min = abs(pos - r);
        }
        printf("%d\n", min + (r - l) + 2);
    }
    return 0;
}
