#include <stdio.h>

int main()
{
    int q;
    scanf("%d", &q);
    while(q--) {
        int n, k, min, max, a;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if(i == 0) {
                min = a;
                max = a;
            } else {
                if(min > a) {
                    min = a;
                }
                if(max < a) {
                    max = a;
                }
            }
        }
        if(min + k < max - k) {
            puts("-1");
        } else {
            printf("%d\n", min + k);
        }
    }
    return 0;
}
