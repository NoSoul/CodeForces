#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        if(d < l) {
            printf("%d\n", d);
        } else {
            int remain = d - r % d;
            printf("%d\n", r + remain);
        }
    }
    return 0;
}
